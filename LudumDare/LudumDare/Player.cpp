#include "Player.h"

void addFramesY(thor::FrameAnimation& animation, int x, int yFirst, int yLast, const sf::Vector2u &size, float duration = 1.f);
void addFramesX(thor::FrameAnimation& animation, int y, int xFirst, int xLast, const sf::Vector2u &size, float duration = 1.f);

Player::Player(sf::Vector2u size)
{
	this->size = size;
	position = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);

	if (!sprites.loadFromFile("hulk.png"))
		std::cerr << "Could not load player image file!";

	sprite.setTexture(sprites);

	addFramesX(left, 1, 0, 3, size); //First 5 Pictures in Row 1 added to left
	addFramesX(right, 2, 0, 3, size); //First 5 Pictures in Row 2 added to right
	addFramesX(stand, 0, 0, 0, size);

	animator.addAnimation("left", left, sf::seconds(1.f));
	animator.addAnimation("right", right, sf::seconds(1.f));
	animator.addAnimation("stand", stand, sf::seconds(1.f));
}


Player::~Player()
{
}

void Player::update(sf::Time &time)
{
	//Pressing A Acceleration to left D to right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x += -PLAYER_ACCELERATION * time.asSeconds();
		if (velocity.x < -PLAYER_MAX_VELOCITY) velocity.x = -PLAYER_MAX_VELOCITY;
		if (!animator.isPlayingAnimation() || animator.getPlayingAnimation() != "left")
			animator.playAnimation("left");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += PLAYER_ACCELERATION * time.asSeconds();
		if (velocity.x > PLAYER_MAX_VELOCITY) velocity.x = PLAYER_MAX_VELOCITY;
		if (!animator.isPlayingAnimation() || animator.getPlayingAnimation() != "right")
			animator.playAnimation("right");
	}
	//If nothing presses accelerated towards 0;
	else
	{
	if (velocity.x > 0)  velocity.x -= 2;
	if (velocity.x < 0) velocity.x += 2;
	}

	if (velocity.y > 0)  velocity.y--;
	if (velocity.y < 0) velocity.y++;
	if (velocity.y > -1.f && velocity.y < 1.f) velocity.y = 0;

	if (position.y + size.y - 1 < yLayer)
		velocity.y += PLAYER_ACCELERATION * time.asSeconds() / 2;
	else if (position.y + size.y + 1 > yLayer)
		velocity.y = 0;

	position += velocity * time.asSeconds();


	if (!animator.isPlayingAnimation()) {
		if (velocity.x > 20) animator.playAnimation("right");
		else if (velocity.x < -10) animator.playAnimation("left");
		else {
			animator.stopAnimation();
			animator.playAnimation("stand");
		}
	}

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

}

//Gets Called when the World registers a collision with player
// 1 = top, 2 = right, 3 = bot, 4 = left
void Player::collide(int dir)
{
	if (DEBUG) std::cout << "Player Collision" << std::endl;
	if (dir == 1 || dir == 3) velocity.y = -velocity.y;
	if (dir == 2 || dir == 4) velocity.x = -velocity.x;
}


void addFramesY(thor::FrameAnimation& animation, int x, int yFirst, int yLast,const sf::Vector2u &size, float duration)
{
	const int step = (yFirst < yLast) ? +1 : -1;
	yLast += step; // so yLast is excluded in the range
	for (int y = yFirst; y != yLast; y += step)
		animation.addFrame(duration, sf::IntRect(size.x * x, size.y * y, size.x, size.y));
}

void addFramesX(thor::FrameAnimation& animation, int y, int xFirst, int xLast, const sf::Vector2u &size, float duration)
{
	const int step = (xFirst < xLast) ? +1 : -1;
	xLast += step; // so yLast is excluded in the range
	for (int x = xFirst; x != xLast; x += step)
		animation.addFrame(duration, sf::IntRect(size.x * x, size.y * y, size.x, size.y));
}