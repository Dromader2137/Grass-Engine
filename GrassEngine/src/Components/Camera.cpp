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
		Vector3f Camera::position;
		Vector3f Camera::rotation;

		void Camera::OnStart()
		{
			std::cout << "Camera init!\n";
		}

		void Camera::Update()
		{
			position = this->gameObject->position;
			rotation = this->gameObject->rotation;

			std::cout << position.x << " " << position.y << " camera's position!\n";
		}

		void Camera::Render()
		{
			std::cout << "Rendering objects:\n";

			if (this->gameObject == nullptr)
			{
				std::cout << "Error: gameObject pointer not set!";
				return;
			}

			std::vector<GameObject*>* gos = this->gameObject->scene->GetObjects();

			for (int i = 0; i < gos->size(); ++i)
			{
				MeshRenderer* mr = gos->at(i)->GetComponent<MeshRenderer>();

				if (mr == nullptr) continue;

				glBindBuffer(GL_ARRAY_BUFFER, mr->vertexBufferId);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mr->indexBufferId);

				glDrawElements(GL_TRIANGLES, mr->indexBuffer.size(), GL_UNSIGNED_INT, nullptr);

				std::cout << gos->at(i)->name << " " << mr->verticies.size() << " " << mr->indexBuffer.size() << "\n";
			}

		}
	}
}
