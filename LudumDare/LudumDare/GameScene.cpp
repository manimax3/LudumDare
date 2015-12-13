#include "GameScene.h"



GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::handleInput(sf::Event &event)
{
	player.handleInput(event);
}

void GameScene::update(sf::Time &frameTime)
{
	player.update(frameTime);
	ghost.update(frameTime);
}

void GameScene::render(sf::RenderWindow &window)
{
	//window.draw(map);
	player.render(window);
	ghost.render(window);
}

void GameScene::load()
{
	resHolder.acquire("sprites", thor::Resources::fromFile<sf::Texture>("data/sprites.png"));
	resHolder.acquire("player", thor::Resources::fromFile<sf::Texture>("data/player.png"));
	resHolder.acquire("entities", thor::Resources::fromFile<sf::Texture>("data/entities.png"));

	player.init(resHolder, sf::Vector2u(128, 128));
	ghost.init(resHolder, sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	//map.load(resHolder, sf::Vector2u(32,32), level, 16, 8);
	finished = false;
}

Scene* GameScene::unload()
{
	return nullptr;
}