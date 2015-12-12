#pragma once
#include "Scene.h"
#include "Player.h"
class GameScene :
	public Scene
{
private:
	Player player;
public:
	GameScene();
	~GameScene();

	void handleInput(sf::Event &event);
	void update(sf::Time &frameTime);
	void render(sf::RenderWindow &window);
	Scene* unload();
	void load();
};

