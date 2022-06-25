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

				void OnStart();
				void Update();
				void Render();

			private:
				float* vertexBuffer;
				unsigned int bufferId;
		};
	}
}