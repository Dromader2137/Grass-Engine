#include <vector>

#include "Scene.h"

namespace grs
{
	std::vector<GameObject>* Scene::GetObjects()
	{
		return &(this->gameObjects);
	}

	Scene::Scene() {}
	Scene::~Scene()
	{
		while (this->gameObjects.empty() != true)
		{
			delete& this->gameObjects.back();
			this->gameObjects.pop_back();
		}
	}
}