#pragma once
#include "Scene.h"
class MenueScene :	public Scene
{
public:
	MenueScene();
	~MenueScene();

	void handleInput(sf::Event &event);
	void update(sf::Time &frameTime);
	void render(sf::RenderWindow &window);
	Scene* unload();
	void load();
};

