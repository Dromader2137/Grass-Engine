#include<vector>
#include<iostream>

#include "GameObject.h"

namespace grs
{
	std::vector<GOComponent*>* GameObject::GetComponents()
	{
		return &(this->components);
	}

	void GameObject::AddComponent(GOComponent* component)
	{
		component->gameObject = this;
		this->components.push_back(component);
	}

	/*template <typename T>
	GOComponent* GameObject::GetComponent()
	{
		std::vector<GOComponent*>* cmps = this->GetComponents();

		for (int i = 0; i < cmps->size(); ++i)
		{
			if (typeid(cmps->at(i)) == typeid(T)) return cmps->at(i);
		}

		return nullptr;
	}*/

	void GameObject::OnStart()
	{
		for (int i = 0; i < this->components.size(); ++i)
		{
			this->components[i]->OnStart();
		}
	}

	void GameObject::Update()
	{
		for (int i = 0; i < this->components.size(); ++i)
		{
			this->components[i]->Update();
		}
	}

	void GameObject::Render()
	{
		for (int i = 0; i < this->components.size(); ++i)
		{
			this->components[i]->Render();
		}
	}

	void GameObject::LateUpdate()
	{
		for (int i = 0; i < this->components.size(); ++i)
		{
			this->components[i]->LateUpdate();
		}
	}
	
	GameObject::GameObject(std::string name, Vector3f position, Vector3f scale, Quaternion rotation)
	{
		this->name = name;

		this->position = position;
		this->scale = scale;
		this->rotation = rotation;
	}
	GameObject::GameObject()
	{
		this->position = Vector3f(0.0f, 0.0f, 0.0f);
		this->rotation = Quaternion();
		this->scale = Vector3f(1.0f, 1.0f, 1.0f);
	}
	GameObject::~GameObject() {}
}