#pragma once

#include "Core.h"

namespace grs
{
	namespace components
	{
		class SimpleRigidbody : public GOComponent
		{
			public:
				Vector3f velocity;
				float mass = 1;

				void AddForce(Vector3f forceVector);

				void Update();
		};
	}
}