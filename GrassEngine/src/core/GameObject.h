#pragma once

#include "../utils/Vector2f.h"

namespace grs
{
	class GameObject
	{
		public:
			Vector2f position;
			float rotation;

			GameObject(Vector2f position, float rotation);
	};
}