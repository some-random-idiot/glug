#pragma once

#include "vector.h"
#include <map>

class Model;

class Entity {
	private:
		unsigned int index;
		Model* model;
		Vector3 position;

	public:
		Entity();

		unsigned int Index();

		void SetPosition(Vector3 pos);

		void SetPosition(float x, float y, float z);

		Vector3 GetPosition();

		void DrawModel();

		void Remove();
};

extern std::map<unsigned int, Entity*> entDict;
