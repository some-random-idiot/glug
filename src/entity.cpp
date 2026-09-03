#include "entity.h"
#include "vector.h"

Entity::Entity() {}

void Entity::SetPosition(Vector3 pos) {
	this->position = pos;
}

void Entity::SetPosition(float x, float y, float z) {
	this->position = Vector3{ x, y, z };
}

Vector3 Entity::GetPosition() {
	return this->position;
}