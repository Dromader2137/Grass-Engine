#pragma once

#include "Scene.h"

namespace grs
{
	class Game
	{
		public:
			/* Start game */
			void StartGame();

			/* Add a new Scene */
			void AddScene(Scene scene);

			Game();
			~Game();

		private:
			/* All active scenes */
			std::vector<Scene> activeScenes;

			bool isRunning = false;
	};
}