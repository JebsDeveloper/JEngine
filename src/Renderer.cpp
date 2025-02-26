#include "Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Transform.h"

Renderer::Renderer(Shader &shader): shader(shader) {

}

Renderer::~Renderer() {
	glDeleteVertexArrays(1, &this -> VAO);
}

void Renderer::initRenderData() {
	unsigned int VBO;

	float vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &this -> VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(this -> VAO);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*) 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Renderer::renderGameObject(GameObject &gameObject, glm::vec3 color) {
	Transform transform = gameObject.getComponent<Transform>();
	Sprite sprite = gameObject.getComponent<Sprite>();

	this -> shader.use();

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(transform.position, 0.0f));
	model = glm::translate(model, glm::vec3(transform.size.x * 0.5f, transform.size.y * 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(transform.rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(transform.size.x * -0.5f, transform.size.y * -0.5f, 0.0f));
	model = glm::scale(model, glm::vec3(transform.size, 1.0f));

	this -> shader.setMat4("model", model);
	this -> shader.setVec3("spriteColor", color);

	glActiveTexture(GL_TEXTURE0);
	sprite.getTexture().bind();

	glBindVertexArray(this -> VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}
