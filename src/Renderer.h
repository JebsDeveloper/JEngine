#pragma once

#include <glad/glad.h>

#include "Shader.h"
#include "GameObject.h"
#include "Sprite.h"

class Renderer {
public:
	Renderer(Shader &shader);
	~Renderer();

	void initRenderData();
	void renderGameObject(GameObject &gameObject, glm::vec3 color = glm::vec3(1.0f));
private:
	Shader shader;

	unsigned int VAO;
};
