#pragma once

#include "../Core.h"
#include "Vertex.h"

namespace grs
{
	namespace components
	{
		class MeshRenderer : public GOComponent
		{
			public:
				std::vector<Vertex> verticies;
		};
	}
}