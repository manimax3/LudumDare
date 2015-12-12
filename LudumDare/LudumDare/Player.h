#pragma once

#include <iostream>
#include <string>

#include <Thor\Animations.hpp>
#include <SFML\Graphics.hpp>


class Player
{
private:
	sf::Texture sprites;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2u size;
	sf::Sprite sprite;

	thor::FrameAnimation stand, left, right, attack;
	thor::Animator<sf::Sprite, std::string> animator;
public:
	Player(sf::Vector2u size);
	~Player();
	void update(sf::Time &time);
	void render(sf::RenderWindow &window);
	void handleInput(sf::Event &event);
	
};

