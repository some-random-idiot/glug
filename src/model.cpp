#include "entity.h"
#include "model.h"

Model::Model(Entity* ent) {
	this->boundEnt = ent;
}

void Model::Draw() {
	// Adds model data to GPU buffers
	// Does not draw stuff on its own

}
