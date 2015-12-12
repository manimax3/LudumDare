#include "Game.h"


Game::Game(int width, int height, char* name)
{
	//Creatin window
	window.create(sf::VideoMode(width, height), name);
	window.setVerticalSyncEnabled(V_SYNC);
	mRunning = true;

	//Adding start screen + loading it
	SceneManager::getInstance()->add(new MenueScene());
	SceneManager::getInstance()->getCurrent()->load();
}

void Game::start()
{
	//Variables for Tick and Render Time Calculation
	sf::Clock clock, tpsClock;
	unsigned int ticks = 0, frames = 0;
	float lastTime = 0;
	double usPerTick = 1000000 / 60;
	double delta = 0;

	//Main Loop calling update() 60 times per sec, updaten() as often as possible
	//and handleInput() on every event
	while (window.isOpen() && mRunning)
	{
		sf::Time time = clock.restart();
		lastTime = lastTime + time.asSeconds();

		delta += tpsClock.restart().asMicroseconds() / usPerTick;
		while (delta >= 1) {
			handleInput();
			update(time);
			delta--;
			ticks++;
		}
		render();
		frames++;


		if (lastTime >= 1) {
			if (DEBUG) {
				std::cout << "FPS: " << frames << " TPS: " << ticks << std::endl;
			}
			ticks = 0;
			frames = 0;
			lastTime = 0;
		}
	}
}

//Forwarding events to the Scene expect Close Event
void Game::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			mRunning = false;
			window.close();
			break;
		}
	SceneManager::getInstance()->getCurrent()->handleInput(event);


	}
}

//Forwarding the updates to the scene
void Game::update(sf::Time &frameTime)
{
	SceneManager::getInstance()->getCurrent()->update(frameTime);

	//If the current scene says its finished SceneManager flips it
	if (SceneManager::getInstance()->getCurrent()->finished)
		SceneManager::getInstance()->flipScene();
}

//Forwarding the render calls to the scene + the render window
void Game::render()
{
	window.clear(sf::Color::Black);
	SceneManager::getInstance()->getCurrent()->render(window);
	window.display();
}

Game::~Game()
{
	mRunning = false;
	SceneManager::remove_instance();
}
