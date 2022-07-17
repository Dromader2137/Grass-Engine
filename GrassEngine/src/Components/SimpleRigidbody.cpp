#include "SimpleRigidbody.h"

namespace grs
{
	namespace components
	{
		void SimpleRigidbody::AddForce(Vector3f forceVector)
		{
			this->velocity += forceVector / this->mass * Game::frameTime;
		}
		void SimpleRigidbody::Update()
		{
			this->gameObject->position += this->velocity * Game::frameTime;
		}
	}
}