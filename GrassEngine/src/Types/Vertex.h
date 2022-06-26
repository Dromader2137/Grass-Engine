#pragma once

#define VERTEX_ELEMENT_COUNT 3

#include "../Types.h"

namespace grs
{
	class Vertex
	{
		public:
			/* Vertex position */
			Vector3f pos;

			Vertex(Vector3f pos);
	};
}