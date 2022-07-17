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

		void MeshRenderer::SetShape(Shape shape)
		{
			switch (shape)
			{
				case Shape::Box:
					this->indexBuffer = std::vector<unsigned int>{ 0, 1, 2, 0, 2, 3, 0, 4, 3, 4, 3, 7, 0, 1, 4, 1, 4, 5, 5, 1, 2, 5, 6, 2, 3, 2, 7, 3, 2, 6, 5, 6, 7, 4, 5, 7 };
					this->verticies = std::vector<float>{1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1};
			}
		}

		void MeshRenderer::OnStart()
		{ 
			material->PrepareShader();
		}
	}
}