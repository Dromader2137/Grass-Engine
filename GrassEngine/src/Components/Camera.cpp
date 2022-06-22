#include <iostream>
#include <typeinfo>

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

		void Camera::Update()
		{
			position = this->gameObject->position;
			rotation = this->gameObject->rotation;

			std::cout << position.x << " " << position.y << " camera's position!\n";
		}

		void Camera::Render()
		{
			std::cout << "Rendering:\n";

			if (this->gameObject == nullptr)
			{
				std::cout << "Error: gameObject not set!";
				return;
			}

			std::vector<GameObject*>* gos = this->gameObject->scene->GetObjects();

			for (int i = 0; i < gos->size(); ++i)
			{
				MeshRenderer* mr = gos->at(i)->GetComponent<MeshRenderer>();

				if (mr == nullptr) continue;

				glBegin(GL_TRIANGLES);
				glVertex2f(mr->a.x, mr->a.y);
				glVertex2f(mr->b.x, mr->b.y);
				glVertex2f(mr->c.x, mr->c.y);
				glEnd();
			}
		}
	}
}
