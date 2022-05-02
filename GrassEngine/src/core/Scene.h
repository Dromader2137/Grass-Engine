#pragma once

#include <vector>

#include "GameObject.h"

namespace grs
{
	class Scene
	{
		public:
			std::vector<GameObject>* GetObjects();

			Scene();
			~Scene();

		private:
			std::vector<GameObject> gameObjects;
	};
}