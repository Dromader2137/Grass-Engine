#pragma once

#include <vector>

#include "../utils/Vector2f.h"
#include "GOComponent.h"

namespace grs
{
	class GameObject
	{
		public:
			Vector2f position;
			float rotation;

			GameObject(Vector2f position, float rotation);

			GameObject();
			~GameObject();

		private:
			std::vector<GOComponent> components;
	};
}