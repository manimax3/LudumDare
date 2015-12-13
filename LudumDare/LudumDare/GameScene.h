#pragma once

#include <Thor\Resources.hpp>

#include "Scene.h"
#include "Player.h"
#include "Map.h"
#include "Ghost.h"
class GameScene :
	public Scene
{
private:
	Player player;
	Map map;
	Ghost ghost;

	thor::ResourceHolder<sf::Texture, std::string> resHolder;
public:
	GameScene();
	~GameScene();

	void handleInput(sf::Event &event);
	void update(sf::Time &frameTime);
	void render(sf::RenderWindow &window);
	Scene* unload();
	void load();
};

