#include <iostream>
#include <typeinfo>
#include <Windows.h>

#include <GL/glew.h>

#include "Camera.h"
#include "MeshRenderer.h"
#include "../Core.h"

namespace grs
{
	namespace components
	{
		float Camera::size;
		Vector3f Camera::position;
		Vector3f Camera::rotation;

		void Camera::OnStart()
		{
			glGenBuffers(1, &bufferId);
		}

		void Camera::Update()
		{
			position = this->gameObject->position;
			rotation = this->gameObject->rotation;

			std::cout << position.x << " " << position.y << " camera's position!\n";
		}

		void Camera::Render()
		{
			if (bufferId == NULL) return;

			std::cout << "Rendering:\n";

			glBindBuffer(GL_ARRAY_BUFFER, bufferId);

			if (this->gameObject == nullptr)
			{
				std::cout << "Error: gameObject pointer not set!";
				return;
			}

			std::vector<GameObject*>* gos = this->gameObject->scene->GetObjects();

			int vertexBufferSize = 0, verticiesCount = 0;
			MeshRenderer* mr;

			for (int i = 0; i < gos->size(); ++i)
			{	
				mr = gos->at(i)->GetComponent<MeshRenderer>();

				if (mr == nullptr) continue;

				vertexBufferSize += mr->verticies.size() * VERTEX_ELEMENT_COUNT;
				verticiesCount += mr->verticies.size();
			}

			delete[] vertexBuffer;
			vertexBuffer = new float[vertexBufferSize];

			int placeInBuffer = 0;

			for (int i = 0; i < gos->size(); ++i)
			{
				mr = gos->at(i)->GetComponent<MeshRenderer>();

				for (int j = 0; j < mr->verticies.size(); ++j)
				{
					vertexBuffer[placeInBuffer] = mr->verticies.at(j).pos.x;
					++placeInBuffer;
					vertexBuffer[placeInBuffer] = mr->verticies.at(j).pos.y;
					++placeInBuffer;
					vertexBuffer[placeInBuffer] = mr->verticies.at(j).pos.z;
					++placeInBuffer;
				}
			}

			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexBufferSize, vertexBuffer, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

			glDrawArrays(GL_TRIANGLES, 0, verticiesCount);

			std::cout << "Vertex buffer size: " << vertexBufferSize << ". Number of verticies: " << verticiesCount << "\n";
		}
	}
}
