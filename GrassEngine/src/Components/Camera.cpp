#include <iostream>
#include <typeinfo>
#include <Windows.h>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
			#ifdef _DEBUG
				std::cout << "-=-=- Camera -=-=-\n\n";
				std::cout << "Camera initialized!\n";
			#endif

			glGenBuffers(1, &this->vertexBufferId);
			glGenBuffers(1, &this->indexBufferId);

			#ifdef _DEBUG
				std::cout << "Vertex buffer id: " << this->vertexBufferId << "\nIndex buffer id: " << this->indexBufferId << "\n";
				std::cout << "\n-=-=-=-=-=-=-=-=-=-\n\n";
			#endif

			glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferId);
		}

		void Camera::Update()
		{
			position = this->gameObject->position;
			rotation = this->gameObject->rotation;
		}

		void Camera::Render()
		{
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

				glm::mat4x4 proj = glm::perspectiveFov<float>(60, this->sizeOnX, this->sizeOnY, 0.01f, 100);
				glm::mat4x4 view = glm::mat4x4(1.0f);
				view = glm::translate(view, (glm::vec3(Camera::position.x / 2, Camera::position.y / 2, -Camera::position.z / 2)));
				glm::mat4x4 model = glm::mat4x4(1.0f);
				model = glm::translate(view, glm::vec3(-mr->gameObject->position.x, -mr->gameObject->position.y, -mr->gameObject->position.z));

				glm::mat4x4 MVP = proj * view * model;

				glUseProgram(mr->material->shader->program);

				mr->material->ApplyParameters();

				glUniformMatrix4fv(glGetUniformLocation(mr->material->shader->program, "u_MVP"), 1, GL_TRUE, &MVP[0][0]);

				glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
				glBufferData(GL_ARRAY_BUFFER, mr->verticies.size() * sizeof(float), mr->GetVerticiesArray(), GL_DYNAMIC_DRAW);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferId);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, mr->indexBuffer.size() * sizeof(unsigned int), mr->GetIndexBufferArray(), GL_DYNAMIC_DRAW);

				glDrawElements(GL_TRIANGLES, mr->indexBuffer.size(), GL_UNSIGNED_INT, nullptr);
			}

		}
	}
}
