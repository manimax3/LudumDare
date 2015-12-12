#include "Player.h"
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\System.hpp>

void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, const sf::Vector2u &size, float duration = 1.f);

Player::Player(sf::Vector2u size)
{
	if (!sprites.loadFromFile("player.png"))
		std::cerr << "Could not load player image file!";
	sprite.setTexture(sprites);
	sprite.setPosition(sf::Vector2f(10, 10));

	this->size = size;
	position = sf::Vector2f(0, 0);

	//addFrames(stand, 0, 0, 4, size); //First 5 Pictures in Row 0 added to stand
	//addFrames(left, 1, 0, 4,size); //First 5 Pictures in Row 1 added to left
	//addFrames(right, 2, 0, 4,size); //First 5 Pictures in Row 2 added to right
	//addFrames(attack, 3, 0, 4,size); //First 5 Pictures in Row 3 added to attack

	stand.addFrame(1.f, sf::IntRect(0, 0, 10, 10));
	stand.addFrame(1.f, sf::IntRect(0, 10, 10, 10));
	stand.addFrame(1.f, sf::IntRect(0, 20, 10, 10));
	stand.addFrame(1.f, sf::IntRect(0, 30, 10, 10));

	animator.addAnimation("stand", stand, sf::seconds(1.f));
	//animator.addAnimation("left", left, sf::seconds(1.f));
	//animator.addAnimation("right", right, sf::seconds(1.f));
	//animator.addAnimation("attack", attack, sf::seconds(1.f));

	//animator.playAnimation("stand", true);

}


Player::~Player()
{
}

void Player::update(sf::Time &time)
{
	//if (velocity.x > 0)  velocity.x--;
	//if (velocity.x < 0) velocity.x++;

	//if (velocity.y > 0)  velocity.y--;
	//if (velocity.y < 0) velocity.y++;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//	velocity.x = -1;

	//position += velocity * time.asSeconds();

	if (!animator.isPlayingAnimation())
		animator.playAnimation("stand");

	animator.update(time);
	animator.animate(sprite);
	//sprite.setPosition(position);
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Player::handleInput(sf::Event &event)
{
	//if (event.type == sf::Event::KeyPressed) {
	//	if (event.key.code == sf::Keyboard::A) animator.playAnimation("left", true);
	//	if (event.key.code == sf::Keyboard::D) animator.playAnimation("right", true);
	//}
	//if (event.type == sf::Event::KeyReleased) {
	//	if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::A)
	//		animator.playAnimation("stand");
	//}
}


void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast,const sf::Vector2u &size, float duration)
{
	const int step = (yFirst < yLast) ? +1 : -1;
	yLast += step; // so yLast is excluded in the range
	for (int y = yFirst; y != yLast; y += step)
		animation.addFrame(duration, sf::IntRect(size.x * x, size.y * y, size.x, size.y));
}