#include "GameScene.h"



GameScene::GameScene() : player(Player(sf::Vector2u(40,56)))
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
}

void GameScene::render(sf::RenderWindow &window)
{
	window.draw(map);
	player.render(window);
}

void GameScene::load()
{
	map.load("sprites.png", sf::Vector2u(32,32), level, 16, 8);
	finished = false;
}

Scene* GameScene::unload()
{
	return nullptr;
}