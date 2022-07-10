#pragma once

#include "../Core.h"

namespace grs
{
	namespace components
	{
		class Camera : public GOComponent
		{
			public:
				float sizeOnX, sizeOnY;
				static Vector3f position;
				static Vector3f rotation;

				unsigned int vertexBufferId;
				unsigned int indexBufferId;

				void OnStart();
				void Update();
				void Render();
		};
	}
}