#include "entity.h"
#include "model.h"

#include <string>
#include <map>

std::map<size_t, Model*> modelRegistry;

bool registerModel(std::string path, Model* model) {
	size_t hash = std::hash<std::string>{}(path);

	if (modelRegistry.find(hash) == modelRegistry.end()) {
		// Model already cached
		return false;
	}

	modelRegistry[hash] = model;
	
	return true;
}

void cacheModel(Model* model) {

}

Model::Model() {
	if (registerModel(path, this)) {
		cacheModel(this);
	}
}

Model::Model(std::string path) {
	// TODO: add support for model file loading (set the verts)
	this->path = path;
	
	if (registerModel(path, this)) {
		cacheModel(this);
	}
}

void Model::Draw() {
	

}
