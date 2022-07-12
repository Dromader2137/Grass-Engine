#include "Game.h"

namespace grs
{
	void Game::StartGame()
	{
		glfwInit();
		this->window = glfwCreateWindow(this->WIDTH, this->HEIGHT, this->WINDOW_NAME.c_str(), NULL, NULL);
		glfwMakeContextCurrent(window);

		glewInit();

		for (int i = 0; i < this->activeScenes.size(); ++i)
		{
			this->activeScenes[i].OnStart();
		}

		while (!glfwWindowShouldClose(window))
		{
			int width, height;
			glfwGetFramebufferSize(window, &width, &height);
			glViewport(0, 0, width, height);
			for (int i = 0; i < this->activeScenes.size(); ++i)
			{
				this->activeScenes[i].Update();
			}
			glClear(GL_COLOR_BUFFER_BIT);
			for (int i = 0; i < this->activeScenes.size(); ++i)
			{
				this->activeScenes[i].Render();
			}
			glfwSwapBuffers(window);
			for (int i = 0; i < this->activeScenes.size(); ++i)
			{
				this->activeScenes[i].LateUpdate();
			}
			glfwPollEvents();
		}
	}

	void Game::AddScene(Scene scene)
	{
		this->activeScenes.push_back(scene);
	}

	Game::Game(int width, int heigth, std::string windowName)
	{
		this->WIDTH = width;
		this->HEIGHT = heigth;
		this->WINDOW_NAME = windowName;
	}
	Game::~Game() {}
}