#pragma once

#include <iostream>
#include <string>

#include <Thor\Animations.hpp>
#include <SFML\Graphics.hpp>
#include <Thor/Resources.hpp>

#include "Variables.h"


class Player
{
private:
	sf::Texture sprites;
	sf::Vector2f velocity;
	sf::Sprite sprite;

	thor::FrameAnimation left, right, stand;
	thor::Animator<sf::Sprite, std::string> animator;

	bool vleft = false, vright = false;
public:
	sf::Vector2f position;
	sf::Vector2u size;

	float yLayer = 600.f;
	Player();
	Player(thor::ResourceHolder<sf::Texture, std::string> &holder, sf::Vector2u size);
	~Player();
	void init(thor::ResourceHolder<sf::Texture, std::string> &holder, sf::Vector2u size);
	void update(sf::Time &time);
	void render(sf::RenderWindow &window);
	void handleInput(sf::Event &event);
	void collide(int dir);
	
};

