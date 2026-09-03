#include <GLFW/glfw3.h>
#include "lib/imgui.h"
#include "lib/imgui_impl_glfw.h"
#include "lib/imgui_impl_opengl3.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	// Resize viewport when the window is resized
	glViewport(0, 0, width, height);
}

GLFWwindow* initGLFW(int width, int height, const char* title) {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	return glfwCreateWindow(width, height, title, NULL, NULL);
}

void initImGui(GLFWwindow* window) {
	// I hate Windows UI syntax so I guess we're rolling with ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	// Using GLFW + OpenGL 3.3
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
}

void initWindow(GLFWwindow* window, int width, int height) {
	glfwMakeContextCurrent(window);

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	initImGui(window);
}

void updateWindow(GLFWwindow* window) {
	glfwPollEvents();

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window);
}

void shutdownWindow(GLFWwindow* window) {
	glfwTerminate();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}