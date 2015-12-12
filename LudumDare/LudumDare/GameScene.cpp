#include "GameScene.h"



GameScene::GameScene() : player(Player(sf::Vector2u(30,30)))
{

}


GameScene::~GameScene()
{

}

void GameScene::handleInput(sf::Event &event)
{
	//player.handleInput(event);
}

void GameScene::update(sf::Time &frameTime)
{
	player.update(frameTime);
}

void GameScene::render(sf::RenderWindow &window)
{
	player.render(window);
}

void GameScene::load()
{
	finished = false;
}

Scene* GameScene::unload()
{
	return nullptr;
}