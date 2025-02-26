#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Callbacks {
public:
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int action, int scancode, int mods);

	static void inputPerFrame(GLFWwindow* window, float deltaTime);
};
