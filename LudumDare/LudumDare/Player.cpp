#include "Player.h"



Player::Player(sf::Vector2u size)
{
	if (!sprites.loadFromFile("data/sprites/player.png"))
		std::cerr << "Could not load player image file!";
	this->size = size;
	addFrames(stand, 0, 0, 4); //First 5 Pictures in Row 0 added to stand
	addFrames(left, 1, 0, 4); //First 5 Pictures in Row 1 added to left
	addFrames(right, 2, 0, 4); //First 5 Pictures in Row 2 added to right
	addFrames(attack, 3, 0, 4); //First 5 Pictures in Row 3 added to attack

	animator.addAnimation("stand", stand, sf::seconds(1.f));
	animator.addAnimation("left", left, sf::seconds(1.f));
	animator.addAnimation("right", right, sf::seconds(1.f));
	animator.addAnimation("attack", attack, sf::seconds(1.f));
}


Player::~Player()
{
}

void Player::update(sf::Time &time)
{
	if ((!animator.isPlayingAnimation()) || ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||
		!(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) &&
		animator.isPlayingAnimation())
	{
		animator.playAnimation("stand", true);
		if (velocity.x > 0) {
			velocity.x--;
			if (velocity.x < 0) velocity.x = 0;
		}
		if (velocity.y > 0) {
			velocity.y--;
			if (velocity.y < 0) velocity.y = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x = -1;

	position += velocity * time.asSeconds();

	animator.update(time);
	animator.animate(sprite);
	sprite.setPosition(position);
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Player::handleInput(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::A) animator.playAnimation("left", true);
		if (event.key.code == sf::Keyboard::D) animator.playAnimation("right", true);
	}
}


void Player::addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f)
{
	const int step = (yFirst < yLast) ? +1 : -1;
	yLast += step; // so yLast is excluded in the range

	for (int y = yFirst; y != yLast; y += step)
		animation.addFrame(duration, sf::IntRect(size.x * x, size.y * y, size.x, size.y));
}