#include "GameObject.h"

namespace grs
{
	GameObject::GameObject(Vector2f position, float rotation)
	{
		this->position = position;
		this->rotation = rotation;
	}
}