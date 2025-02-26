#include "Window.h"

#include <stdexcept>
#include <iostream>

#include "Globals.h"

#include "Transform.h"

#define REMOVE_IMGUI 0

#if REMOVE_IMGUI == 0
	#include "imgui.h"
	#include "backends/imgui_impl_glfw.h"
	#include "backends/imgui_impl_opengl3.h"
#endif

#include "Callbacks.h"

Window::Window(unsigned int width, unsigned int height, const char* title) {
	this -> width = width;
	this -> height = height;
	this -> title = title;
}

Window::~Window() {

}

void Window::init() {
	if (!glfwInit()) {
		throw std::runtime_error("Failed to initialize GLFW.");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	this -> window = glfwCreateWindow(this -> width, this -> height, this -> title, nullptr, nullptr);

	if (this -> window == nullptr) {
		throw std::runtime_error("Failed to create GLFW window.");
	}

	glfwMakeContextCurrent(this -> window);

	glfwSetFramebufferSizeCallback(this -> window, Callbacks::framebufferSizeCallback);
	glfwSetKeyCallback(this -> window, Callbacks::keyCallback);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		throw std::runtime_error("Failed to initialize GLAD.");
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

#if REMOVE_IMGUI == 0
	ImGui::CreateContext();

	ImGuiIO &io = ImGui::GetIO();
	(void) io;

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(this -> window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
#endif
}

float floatyFloat = 0.0f;

void Window::update() {
#if REMOVE_IMGUI == 0
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// ImGui

	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif

	glfwSwapBuffers(this -> window);
	glfwPollEvents();
}

void Window::cleanup() {
#if REMOVE_IMGUI == 0
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
#endif

	glfwTerminate();
}

unsigned int Window::getWidth() {
	return this -> width;
}

unsigned int Window::getHeight() {
	return this -> height;
}

bool Window::windowShouldClose() {
	return glfwWindowShouldClose(this -> window);
}

GLFWwindow* Window::getWindow() {
	return this -> window;
}
