#pragma once

#define MAX_UINT16 65536

class Entity;

class Model {
	private:
		Entity* boundEnt;  // Model must be bound to an entity
		float vertices[MAX_UINT16] = {
			// Models initialized without a model data starts as a cube by default

			// Front vertices
			-0.5f, 0.5f, -0.5f,
			0.5f, 0.5f, -0.5,
			-0.5f, -0.5f, -0.5,
			0.5f, -0.5f, -0.5,

			// Back vertices
			-0.5f, 0.5f, 0.5,
			0.5f, 0.5f, 0.5,
			-0.5f, -0.5f, 0.5,
			0.5f, -0.5f, 0.5,
		};

	public:
		Model(Entity* ent);

		void Draw();
};