#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.h"

namespace grs
{
	class Game
	{
		public:
			/* Window in which the application run */
			static GLFWwindow* window;

			/* Start game */
			void StartGame();

			/* Add a new Scene */
			void AddScene(Scene scene);

			Game(int width, int heigth, std::string);
			~Game();

		private:
			/* All active scenes */
			std::vector<Scene> activeScenes;

			/* Window dimensions */
			int WIDTH, HEIGHT;
			/* Window name */
			std::string WINDOW_NAME;
	};
}