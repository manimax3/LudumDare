#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

#include "Variables.h"
#include "SceneManager.h"
#include "MenueScene.h"

class Game
{
private:
	bool mRunning;
	sf::RenderWindow window;
public:
	Game(int width, int height, char* name);
	~Game();
	void start();
private:
	void handleInput();
	void update(sf::Time &frameTime);
	void render();
};

