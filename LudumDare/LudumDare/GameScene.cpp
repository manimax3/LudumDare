#include "GameScene.h"



GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::handleInput(sf::Event &event)
{
	mHandler.handleInput(event);
}

void GameScene::update(sf::Time &frameTime)
{
	mHandler.update(frameTime);
}

void GameScene::render(sf::RenderWindow &window)
{
	window.draw(map);
	mHandler.render(window);
}

void GameScene::load()
{
	LevelGenerator lGen(LevelType::STANDARD, 3, 30, 20);

	resHolder.acquire("sprites", thor::Resources::fromFile<sf::Texture>("data/sprites.png"));
	resHolder.acquire("player", thor::Resources::fromFile<sf::Texture>("data/player.png"));
	resHolder.acquire("entities", thor::Resources::fromFile<sf::Texture>("data/entities.png"));

	mHandler.init(resHolder);
	map.load(resHolder, sf::Vector2u(32,32), lGen.generateLevel(), 30, 20);
	finished = false;
}

Scene* GameScene::unload()
{
	return nullptr;
}