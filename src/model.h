#pragma once

#include <string>

#define MAX_UINT16 65536

class Model {
	private:
		// Models initialized without a model file starts as a cube by default
		std::string path = "cube";  // Also used as ID
		float vertices[MAX_UINT16] = {
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
		Model();

		Model(std::string path);
};
