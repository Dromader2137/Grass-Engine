#pragma once

#include "../Core.h"

namespace grs
{
	namespace components
	{
		class Camera : public GOComponent
		{
			public:
				static float size;
				static Vector3f position;
				static Vector3f rotation;

				void Update();
				void Render();
		};
	}
}