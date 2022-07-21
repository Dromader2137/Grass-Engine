#pragma once

#include "Core.h"

namespace grs
{
	namespace components
	{
		class Camera : public GOComponent
		{
			public:
				float FOV = 75;
				
				
				static Vector3f position;
				static Quaternion rotation;

				unsigned int vertexBufferId;
				unsigned int indexBufferId;

				void OnStart();
				void Update();
				void Render();
		};
	}
}