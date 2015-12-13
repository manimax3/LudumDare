#include "Ghost.h"



Ghost::Ghost(thor::ResourceHolder<sf::Texture, std::string> &holder, sf::Vector2f position)
{
	sprite.setTexture(holder["entities"]);
	sprite.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	sprite.setPosition(position);
	relPosition = position;
	m_Position = position;
	m_Velocity.x = 0.f;
	m_Velocity.y = 0.f;
}

Ghost::Ghost()
{
}

Ghost::~Ghost()
{
}

void Ghost::init(thor::ResourceHolder<sf::Texture, std::string> &holder, sf::Vector2f position)
{
	sprite.setTexture(holder["entities"]);
	sprite.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	sprite.setPosition(position);
	relPosition = position;
	m_Position = position;
	m_Velocity.x = 0.f;
	m_Velocity.y = 0.f;
}

void Ghost::update(sf::Time &time)
{
	m_Velocity.x += thor::random(-2.f, 2.f);
	m_Velocity.y += thor::random(-2.f, 2.f);
	m_Position += m_Velocity * time.asSeconds();
	sprite.setPosition(m_Position);
}

void Ghost::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}