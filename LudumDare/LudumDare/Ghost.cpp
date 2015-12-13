#include "Ghost.h"

Ghost::Ghost()
{
}

Ghost::~Ghost()
{
}

void Ghost::init(thor::ResourceHolder<sf::Texture, std::string> &holder, sf::Vector2f position)
{
	sprite.setTexture(holder["entities"]);

	bool type = thor::random(false, true);
	if(type) sprite.setTextureRect(sf::IntRect(SIZE, 0, SIZE, SIZE));
	else sprite.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));

	float scale = thor::random(.8f, 1.4f);
	transform.scale(scale, scale);

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
	window.draw(sprite, transform);
}

void Ghost::handleInput(sf::Event &event)
{

}
