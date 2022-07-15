#pragma once

#include "../Core.h"
#include "../MaterialSystem.h"

namespace grs
{
	namespace components
	{
		class MeshRenderer : public GOComponent
		{
			public:
				std::vector<float> verticies;
				std::vector<unsigned int> indexBuffer;

				grs::mat::Material* material;

				void AddVertex(Vertex vertex);

				float* GetVerticiesArray();
				unsigned int* GetIndexBufferArray();

				void OnStart();
		};
	}
}
