#pragma once
#include <SFML\Graphics.hpp>
#include <Thor\Resources.hpp>
#include <Thor\Math.hpp>
#include "Variables.h"

#define SIZE 32

class Ghost
{
private:
	sf::Sprite sprite;
	sf::Vector2f m_Position, m_Velocity, relPosition;
	sf::Transform transform;
public:
	Ghost();
	~Ghost();
	void init(thor::ResourceHolder<sf::Texture, std::string> &holder, sf::Vector2f position);
	void update(sf::Time &time);
	void render(sf::RenderWindow &window);
	void handleInput(sf::Event &event);

	inline sf::Vector2f getPosition() { return m_Position; }
};

