#include <GLFW/glfw3.h>

#include <iostream>

#include "lib/imgui.h"
#include "lib/imgui_impl_glfw.h"
#include "lib/imgui_impl_opengl3.h"

#include "goop.h"
#include "input.h"
#include "render.h"
#include "window.h"

#define WIDTH 800
#define HEIGHT 600

int main() {
	GLFWwindow* window = initGLFW(WIDTH, HEIGHT, "Glug");

	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}

	initWindow(window, WIDTH, HEIGHT);

	int result = initRenderer();
	if (result == -1) {
		return result;
	}

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		updateWindow(window);
	}

	shutdownWindow(window);

	return 0;
}