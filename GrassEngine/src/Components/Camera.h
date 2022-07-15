#pragma once

#include "../Core.h"

namespace grs
{
	namespace components
	{
		class Camera : public GOComponent
		{
			public:
				float size = 1;
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