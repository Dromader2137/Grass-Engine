#pragma once

#include <vector>

#include "GameObject.h"

namespace grs
{
	class GameObject;

	class Scene
	{
		public:
			/* Scene's name */
			std::string name;

			/* Return pointers to all Game Objects in a Scene */
			std::vector<GameObject*>* GetObjects();

			/* Add a GameObject to the Scene */
			void AddGameObject(GameObject* gameObject);

			void OnStart();
			void Update();
			void Render();
			void LateUpdate();

			Scene(std::string name);
			Scene();
			~Scene();

		private:
			/* List of all GameObjects in a Scene */
			std::vector<GameObject*> gameObjects;
	};
}