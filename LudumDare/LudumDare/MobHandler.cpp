#include "MobHandler.h"



MobHandler::MobHandler()
{
}


MobHandler::~MobHandler()
{
}

void MobHandler::init(thor::ResourceHolder<sf::Texture, std::string> &holder)
{
	sf::Image image;
	image.loadFromFile("data/map1.png");
	mapSize = image.getSize();
	for (unsigned int y = 0; y < mapSize.y; ++y) {
		for (unsigned int x = 0; x < mapSize.x; ++x) {
			if (image.getPixel(x, y) == sf::Color::Red) {
				Ghost ghost;
				ghost.init(holder, sf::Vector2f(x, y));
				ghosts.push_back(ghost);
			}
		}
	}

	player.init(holder, sf::Vector2u(128, 128));
}

void MobHandler::update(sf::Time &time)
{
	int i = 0;
	for (auto it = ghosts.begin(); it != ghosts.end(); ++it) {
		ghosts.at(i).update(time);
		i++;
	}

	player.update(time);
}
void MobHandler::render(sf::RenderWindow &window)
{
	int i = 0;
	for (auto it = ghosts.begin(); it != ghosts.end(); ++it) {
		if (ghosts.at(i).getPosition().x > WIDTH || ghosts.at(i).getPosition().x < 0
			|| ghosts.at(i).getPosition().y > HEIGHT || ghosts.at(i).getPosition().y < 0)
		{
			i++; continue;
		}
		ghosts.at(i).render(window);
		i++;
	}
	player.render(window);
}
void MobHandler::handleInput(sf::Event &event)
{
	player.handleInput(event);
}