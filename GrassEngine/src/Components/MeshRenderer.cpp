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

		void MeshRenderer::OnStart()
		{
			glGenBuffers(1, &(this->vertexBufferId));
			glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->verticies.size(), this->GetVerticiesArray(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

			glGenBuffers(1, &(this->indexBufferId));
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer.size() * sizeof(unsigned int), this->GetIndexBufferArray(), GL_STATIC_DRAW);
		}
	}
}