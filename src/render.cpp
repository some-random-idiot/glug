#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

unsigned int staticVBO;
unsigned int staticVBOIndex = 0;

void initRenderer() {
	glGenBuffers(1, &staticVBO);
}

unsigned int allocateStaticVBO(float vertices[]) {
	glBindBuffer(GL_ARRAY_BUFFER, staticVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	staticVBOIndex += 1;
	
	return staticVBOIndex;
}

void loadShader(std::string path) {
	fs::path pathObj(path);
	fs::path extension = pathObj.extension();

	std::ifstream fileStream(path);
	std::stringstream stringStream;

	stringStream << fileStream.rdbuf();
	
	std::string shaderCode = stringStream.str();

	if (extension == ".vert") {

	}
	if (extension == ".frag") {

	}
}
 