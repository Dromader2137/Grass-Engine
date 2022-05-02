#include<vector>

#include "GameObject.h"

namespace grs
{
	GameObject::GameObject(Vector2f position, float rotation)
	{
		this->position = position;
		this->rotation = rotation;
	}

	GameObject::GameObject()
	{
		this->position = Vector2f(0.0f, 0.0f);
		this->rotation = 0.0f;
	}

	GameObject::~GameObject()
	{
		while (this->components.empty() != true)
		{
			delete &this->components.back();
			this->components.pop_back();
		}
	}
}