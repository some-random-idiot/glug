#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "lib/imgui.h"
#include "lib/imgui_impl_glfw.h"
#include "lib/imgui_impl_opengl3.h"

#include "window.h"
#include "input.h"
#include "goop.h"
#include "render.h"

#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main() {
	Goop goop;
	Goop goop2;

	GLFWwindow* window = initGLFW(WIDTH, HEIGHT, "Glug");

	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}

	initWindow(window, WIDTH, HEIGHT);

	// Load OpenGL function addresses
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return -1;
	}

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		updateWindow(window);
		renderEntities();
	}

	shutdownWindow(window);

	return 0;
}