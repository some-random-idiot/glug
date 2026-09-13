#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

unsigned int staticVBO;
unsigned int staticVBOIndex = 0;

unsigned int allocateStaticVBO(float vertices[]) {
	glBindBuffer(GL_ARRAY_BUFFER, staticVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	staticVBOIndex += 1;

	return staticVBOIndex;
}

std::map<std::string, unsigned int> vertShaderRegistry;
std::map<std::string, unsigned int> fragShaderRegistry;

void initShaders() {

}

void compileShader(std::string path) {
	fs::path pathObj(path);
	fs::path extension = pathObj.extension();

	std::ifstream fileStream(path);
	std::stringstream stringStream;

	stringStream << fileStream.rdbuf();

	std::string shaderSrc = stringStream.str();
	const char* shaderSrcPtr = shaderSrc.c_str();
	unsigned int shader;

	if (extension == ".vert") {
		shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(shader, 1, &shaderSrcPtr, NULL);

		vertShaderRegistry[path] = shader;

		glCompileShader(shader);
	}
	if (extension == ".frag") {
		shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(shader, 1, &shaderSrcPtr, NULL);

		fragShaderRegistry[path] = shader;

		glCompileShader(shader);
	}
}

void initRenderer() {
	// Buffers
	glGenBuffers(1, &staticVBO);

	// Shaders
	initShaders();
}
