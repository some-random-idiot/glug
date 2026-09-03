#pragma once

#include <string>

class Vector3 {
	private:
		float x = 0, y = 0, z = 0;
	
	public:
		Vector3();

		Vector3(float x, float y, float z);

		std::string toString();
};
