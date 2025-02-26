#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(unsigned int width, unsigned int height, const char* title);
	~Window();

	void init();
	void update();
	void cleanup();

	unsigned int getWidth();
	unsigned int getHeight();

	bool windowShouldClose();
	GLFWwindow* getWindow();
private:
	unsigned int width;
	unsigned int height;
	const char* title;

	GLFWwindow* window;
};
