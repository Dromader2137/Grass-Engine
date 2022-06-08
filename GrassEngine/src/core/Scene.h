#pragma once

#include <vector>

#include "GameObject.h"

namespace grs
{
	class Scene
	{
		public:
			/* Return pointers to all Game Objects in a Scene */
			std::vector<GameObject>* GetObjects();

			/* Add a GameObject to the Scene */
			void AddGameObject(GameObject gameObject);

			void Update();

			Scene();
			~Scene();

		private:
			/* List of all GameObjects in a Scene */
			std::vector<GameObject> gameObjects;
	};
}