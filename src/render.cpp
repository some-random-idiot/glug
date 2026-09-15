// Shader paths are relative to the shader folder. Keep this in mind when adding shaders to the project.

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

const std::string ROOT_SHADER_PATH = "shader/";

unsigned int staticVBO;
unsigned int staticVBOIndex = 0;

unsigned int allocateStaticVBO(float vertices[]) {
	glBindBuffer(GL_ARRAY_BUFFER, staticVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	staticVBOIndex += 1;

	return staticVBOIndex;
}

void initShaders() {
	
}

std::map<std::string, unsigned int> shaderProgramRegistry;

void linkShaderProgram(std::string name, std::vector<std::string> shaderPaths) {
	size_t pathCount = shaderPaths.size();

	if (pathCount == 0) {
		std::cout << "Shader program creation failed: no paths were provided." << std::endl;
		return;
	}

	std::vector<unsigned int> compiledShaders;

	for (std::string path : shaderPaths) {
		compiledShaders.push_back(compileShader(path));
	}

	unsigned int shaderProgram;

	for (unsigned int shader : compiledShaders) {
		glAttachShader(shaderProgram, shader);
	}

	glLinkProgram(shaderProgram);

	shaderProgramRegistry[name] = shaderProgram;
}

unsigned int compileShader(std::string shaderPath) {
	fs::path pathObj(ROOT_SHADER_PATH + shaderPath);
	fs::path extension = pathObj.extension();

	std::ifstream fileStream(shaderPath);
	std::stringstream stringStream;

	stringStream << fileStream.rdbuf();

	std::string shaderSrc = stringStream.str();
	const char* shaderSrcPtr = shaderSrc.c_str();
	unsigned int shader;

	if (extension == ".vert") {
		shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(shader, 1, &shaderSrcPtr, NULL);
	}
	if (extension == ".frag") {
		shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(shader, 1, &shaderSrcPtr, NULL);
	}

	glCompileShader(shader);

	// Error logging
	int  success;
	char infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Failed to compile a shader:\n" << infoLog << std::endl;
	}

	return shader;
}

int initRenderer() {
	// Load OpenGL function addresses
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return -1;
	}

	// Buffers
	glGenBuffers(1, &staticVBO);

	// Shaders
	initShaders();

	return 0;
}
