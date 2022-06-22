#include <iostream>

#include "Core.h"
#include "Components.h"

int main()
{
	grs::Game game = grs::Game(1280, 720, "Game");

	grs::Scene mainScene = grs::Scene("Game");
	grs::GameObject player = grs::GameObject("Player", grs::Vector3f(10.5f, 0.0f, -10.0f), grs::Vector3f(0.0f, 0.0f, 0.0f));
	grs::components::Camera camera = grs::components::Camera();
	player.AddComponent(&camera);
	grs::components::MeshRenderer renderer = grs::components::MeshRenderer();
	renderer.a = grs::Vector3f(0.0f, 0.5f, 0.0f);
	renderer.b = grs::Vector3f(-0.5f, -0.5f, 0.0f);
	renderer.c = grs::Vector3f(0.5f, -0.5f, 0.0f);
	player.AddComponent(&renderer);
	mainScene.AddGameObject(&player);

	game.AddScene(mainScene);

	game.StartGame();
	
}