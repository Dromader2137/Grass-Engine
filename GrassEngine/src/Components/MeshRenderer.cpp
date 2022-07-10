#include "MeshRenderer.h"

namespace grs
{
	namespace components
	{
		void MeshRenderer::AddVertex(Vertex vertex)
		{
			this->verticies.push_back(vertex.pos.x);
			this->verticies.push_back(vertex.pos.y);
			this->verticies.push_back(vertex.pos.z);
		}

		float* MeshRenderer::GetVerticiesArray()
		{
			return &(this->verticies[0]);
		}

		unsigned int* MeshRenderer::GetIndexBufferArray()
		{
			return &(this->indexBuffer[0]);
		}
	}
}