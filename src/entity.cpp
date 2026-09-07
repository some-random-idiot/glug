#include "entity.h"
#include "model.h"
#include "vector.h"

#include <map>
#include <queue>
#include <iostream>

std::map<unsigned int, Entity*> entDict;
std::queue<unsigned int> recycleIndex;
unsigned int nextIndex = 0;

Entity::Entity() {
	this->model = new Model();

	// Use recyclable indices when there is one
	if (recycleIndex.size() < 1) {
		this->index = nextIndex;
		entDict[nextIndex] = this;
		nextIndex += 1;
	}
	else {
		const unsigned int index = recycleIndex.front();

		this->index = index;
		entDict[index] = this;
		recycleIndex.pop();
	}
}

unsigned int Entity::Index() {
	return this->index;
}

void Entity::SetPosition(Vector3 pos) {
	this->position = pos;
}

void Entity::SetPosition(float x, float y, float z) {
	this->position = Vector3{ x, y, z };
}

Vector3 Entity::GetPosition() {
	return this->position;
}

void Entity::DrawModel() {
	this->model->Draw();
}

void Entity::Remove() {
	// Remove from EntDict and mark index for recycling
	const unsigned int index = this->index;

	recycleIndex.push(index);
	entDict.erase(index);
}