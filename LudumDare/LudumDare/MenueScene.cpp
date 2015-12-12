#include "MenueScene.h"

#include "GameScene.h"

MenueScene::MenueScene()
{
}


MenueScene::~MenueScene()
{

}

void MenueScene::handleInput(sf::Event &event)
{

}

void MenueScene::update(sf::Time &frameTime)
{

}

void MenueScene::render(sf::RenderWindow &window)
{

}

Scene* MenueScene::unload()
{
	return new GameScene();
}

void MenueScene::load()
{
	finished = true;
}