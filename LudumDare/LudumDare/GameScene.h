#pragma once

#include <Thor\Resources.hpp>

#include "Scene.h"
#include "Map.h"
#include "MobHandler.h"
#include "LevelGenerator.h"
class GameScene :
	public Scene
{
private:
	Player player;
	Map map;
	MobHandler mHandler;

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

