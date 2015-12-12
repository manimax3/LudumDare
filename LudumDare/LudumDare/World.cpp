#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::load()
{
	map.load("/sprites/tiles.png", sf::Vector2u(32, 32));
}

void World::update(sf::Time &frameTime)
{

}

void World::render(sf::RenderWindow &window)
{

}
void World::handleInput(sf::Event &event)
{

}