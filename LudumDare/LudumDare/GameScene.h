#pragma once
#include "Scene.h"
class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void handleInput(sf::Event &event);
	void update(sf::Time &frameTime);
	void render(sf::RenderWindow &window);
	Scene* unload();
	void load();
};

