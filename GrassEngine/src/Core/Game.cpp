#include "Game.h"

namespace grs
{
	void Game::StartGame()
	{
		this->isRunning = true;
		while (this->isRunning)
		{
			for (int i = 0; i < this->activeScenes.size(); ++i)
			{
				this->activeScenes[i].Update();
			}
		}
	}

	void Game::AddScene(Scene scene)
	{
		this->activeScenes.push_back(scene);
	}

	Game::Game() {}
	Game::~Game() {}
}