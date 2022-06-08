#include <vector>

#include "Scene.h"

namespace grs
{
	std::vector<GameObject>* Scene::GetObjects()
	{
		return &(this->gameObjects);
	}

	void Scene::AddGameObject(GameObject gameObject)
	{
		this->gameObjects.push_back(gameObject);
	}

	void Scene::Update()
	{
		for (int i = 0; i < this->gameObjects.size(); ++i)
		{
			this->gameObjects[i].Update();
		}
	}

	Scene::Scene() {}
	Scene::~Scene() {}
}