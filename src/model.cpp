#include "entity.h"
#include "model.h"
#include "render.h"

#include <string>
#include <map>

std::map<std::string, Model*> modelRegistry;
std::map<std::string, float*> modelIndexRegistry;

bool registerModel(std::string path, Model* model) {
	if (modelRegistry.find(path) == modelRegistry.end()) {
		// Model already cached
		return false;
	}

	modelRegistry[path] = model;
	
	return true;
}

void cacheModel(std::string path, float vertices[]) {
	unsigned int index = allocateStaticVBO(vertices);
	modelIndexRegistry[path] = vertices;
}

Model::Model() {
	if (registerModel(path, this)) {
		cacheModel(this->path, this->vertices);
	}
}

Model::Model(std::string path) {
	this->path = path;

	// TODO: add support for model file loading (set the verts)
	
	if (registerModel(path, this)) {
		cacheModel(this->path, this->vertices);
	}
}
