#pragma once

#include "vector.h"

class Entity {
	private:
		Vector3 position;

	public:
		Entity();

		void SetPosition(Vector3 pos);

		void SetPosition(float x, float y, float z);

		Vector3 GetPosition();
};