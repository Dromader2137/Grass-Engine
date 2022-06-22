#include <vector>
#include <iostream>

#include "Scene.h"

namespace grs
{
	std::vector<GameObject*>* Scene::GetObjects()
	{
		return &(this->gameObjects);
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		gameObject->scene = this;
		this->gameObjects.push_back(gameObject);
	}
	
	void Scene::OnStart()
	{
		for (int i = 0; i < this->gameObjects.size(); ++i)
		{
			this->gameObjects[i]->OnStart();
		}
	}

	void Scene::Update()
	{
		for (int i = 0; i < this->gameObjects.size(); ++i)
		{
			this->gameObjects[i]->Update();
		}
	}
	
	void Scene::Render()
	{
		for (int i = 0; i < this->gameObjects.size(); ++i)
		{
			this->gameObjects[i]->Render();
		}
	}
	
	void Scene::LateUpdate()
	{
		for (int i = 0; i < this->gameObjects.size(); ++i)
		{
			this->gameObjects[i]->LateUpdate();
		}
	}

	Scene::Scene(std::string name)
	{
		this->name = name;
	}

	Scene::Scene() {}
	Scene::~Scene() {}
}