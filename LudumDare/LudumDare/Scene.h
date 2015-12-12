#pragma once
#include "SFML\Graphics.hpp"
#include "Variables.h"
class Scene
{
public:
	bool finished;
public:
	Scene();
	virtual ~Scene();

	virtual void handleInput(sf::Event &event);
	virtual void update(sf::Time &frameTime);
	virtual void render(sf::RenderWindow &window);
	virtual Scene* unload();
	virtual void load();
};

