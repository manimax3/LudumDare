#pragma once

#include <vector>

#include "SFML\Graphics.hpp"
#include "Map.h"
class World
{
private:
	Map map;
public:
	World();
	~World();

	void load();
	void update(sf::Time &frameTime);
	void render(sf::RenderWindow &window);
	void handleInput(sf::Event &event);
};

