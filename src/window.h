#pragma once

GLFWwindow* initGLFW(int width, int height, const char* title);
void initWindow(GLFWwindow* window, int width, int height);
void updateWindow(GLFWwindow* window);
void shutdownWindow(GLFWwindow* window);
