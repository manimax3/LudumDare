#pragma once

#include <SFML\Graphics.hpp>
#include <Thor\Resources.hpp>
#include <vector>
#include <memory>
#include "Ghost.h"
#include "Player.h"

class MobHandler
{
private:
	std::vector<Ghost> ghosts;
	Player player;
	sf::Vector2u mapSize;
public:
	MobHandler();
	~MobHandler();
	void init(thor::ResourceHolder<sf::Texture, std::string> &holder);
	void update(sf::Time &time);
	void render(sf::RenderWindow &window);
	void handleInput(sf::Event &event);
};

