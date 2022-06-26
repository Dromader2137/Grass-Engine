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

				unsigned int vertexBufferId;
				unsigned int indexBufferId;

				void AddVertex(Vertex vertex);

				float* GetVerticiesArray();
				unsigned int* GetIndexBufferArray();

				void OnStart();
		};
	}
}