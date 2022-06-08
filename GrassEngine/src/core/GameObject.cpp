#include<vector>

#include "GameObject.h"

namespace grs
{
	void GameObject::AddComponent(std::shared_ptr<GOComponent> component)
	{
		this->components.push_back(component);
	}

	void GameObject::Update()
	{
		for (int i = 0; i < this->components.size(); ++i)
		{
			this->components[i]->Update();
		}
	}
	
	GameObject::GameObject(std::string name, Vector2f position, float rotation)
	{
		this->name = name;

		this->position = position;
		this->rotation = rotation;
	}
	GameObject::GameObject()
	{
		this->position = Vector2f(0.0f, 0.0f);
		this->rotation = 0.0f;
	}
	GameObject::~GameObject() {}
}