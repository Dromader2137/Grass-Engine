#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Scene.h"
#include "GOComponent.h"

namespace grs
{
	class Scene;

	class GameObject
	{
		public:
			/* Parent Scene */
			Scene* scene;

			/* Object's name */
			std::string name;
			
			/* Object's position */
			Vector3f position;
			/* Object's rotation in radians */
			Vector3f rotation;

			/* Return pointers to all GOComponents in a GameObject */
			std::vector< GOComponent* >* GetComponents();

			/* Adds a component to the GameObject */
			void AddComponent(GOComponent* component);

			template <class T>
			T* GetComponent();

			void OnStart();
			void Update();
			void Render();
			void LateUpdate();

			GameObject(std::string name, Vector3f position, Vector3f rotation);
			GameObject();
			~GameObject();

		private:
			/* List of all components a GameObject has */
			std::vector<GOComponent*> components;
	};
}