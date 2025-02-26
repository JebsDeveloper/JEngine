#include "Callbacks.h"

#include "Globals.h"

void Callbacks::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Callbacks::keyCallback(GLFWwindow* window, int key, int action, int scancode, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(window, true);
		}
	}
}

void Callbacks::inputPerFrame(GLFWwindow* window, float deltaTime) {
	Transform &playerTransform = Globals::player -> getComponent<Transform>();

	if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) && Globals::playerCollision != TOP) {
		playerTransform.position.y -= 500.0f * deltaTime;
	} if ((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) && Globals::playerCollision != BOTTOM) {
		playerTransform.position.y += 500.0f * deltaTime;
	}

	if ((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) && Globals::playerCollision != LEFT) {
		playerTransform.position.x -= 500.0f * deltaTime;
	} else if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) && Globals::playerCollision != RIGHT) {
		playerTransform.position.x += 500.0f * deltaTime;
	}
}
