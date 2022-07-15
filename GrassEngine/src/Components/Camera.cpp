#include <iostream>
#include <typeinfo>
#include <Windows.h>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

//#include <GLFW/glfw3.h>

#include "Camera.h"
#include "MeshRenderer.h"
#include "Core.h"

namespace grs
{
	namespace components
	{
		Vector3f Camera::position;
		glm::quat Camera::rotation;

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

				int w = 1, h = 1;

				glfwGetWindowSize(Game::window, &w, &h);

				glm::mat4x4 proj = glm::perspectiveFovRH<float>(glm::radians(this->FOV), 1, (float)(((float)h) / ((float)w)), 0.1f, 100);
				glm::quat cameraQuaternion = glm::quat(glm::vec3(Camera::rotation.x, -Camera::rotation.y, Camera::rotation.z));
				glm::mat4x4 view = glm::lookAtRH(glm::vec3(0), glm::vec3(0, 0, 1) * cameraQuaternion, glm::vec3(0, 1, 0) * cameraQuaternion);
				view = glm::translate(view, glm::vec3(Camera::position.x, Camera::position.y, -Camera::position.z));
				glm::vec3 modelEuler = glm::eulerAngles(mr->gameObject->rotation);
				glm::mat4x4 model = glm::mat4x4(1.0f);
				model = glm::translate(model, glm::vec3(-mr->gameObject->position.x, mr->gameObject->position.y, mr->gameObject->position.z));
				model = glm::rotate(model, modelEuler.x, glm::vec3(1, 0, 0));
				model = glm::rotate(model, modelEuler.y, glm::vec3(0, 1, 0));
				model = glm::rotate(model, modelEuler.z, glm::vec3(0, 0, 1));

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
