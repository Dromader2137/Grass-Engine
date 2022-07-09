#pragma once

#include "../Core.h"

namespace grs
{
	namespace components
	{
		class MeshRenderer : public GOComponent
		{
			public:
				std::vector<float> verticies;
				std::vector<unsigned int> indexBuffer;

				void AddVertex(Vertex vertex);

				float* GetVerticiesArray();
				unsigned int* GetIndexBufferArray();
		};
	}
}
