#include <iostream>

#include "Core.h"

class DebugComponent : public grs::GOComponent
{
	public:
		std::string ot;

		void Update()
		{
			std::cout << "Updated!" + ot + "\n";
		}
};

int main()
{
	grs::Game game = grs::Game();

	grs::Scene mainScene = grs::Scene();
	grs::GameObject player = grs::GameObject("Player", grs::Vector2f(10.5f, 0.0f), 0.0f);
	DebugComponent dbg = DebugComponent();
	dbg.ot = " xd";
	player.AddComponent(std::make_shared<DebugComponent>(dbg));
	mainScene.AddGameObject(player);

	game.AddScene(mainScene);

	game.StartGame();
}