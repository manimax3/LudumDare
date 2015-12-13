#pragma once
#include <iostream>
#include <vector>
#include "SFML\Graphics.hpp"
#include "Thor\Math.hpp"
#include "Thor\Resources.hpp"
#include "Variables.h"
class Map : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture m_SpriteSheet;
	sf::VertexArray m_Vertices;
public:
	Map();
	~Map();
	void load(thor::ResourceHolder<sf::Texture, std::string> &holder,
		      sf::Vector2u tileSize, const int *tileSet, unsigned int width, unsigned int height);
	void load(thor::ResourceHolder<sf::Texture, std::string> &holder,
		sf::Vector2u tileSize, const std::vector<unsigned int> tiles, unsigned int width, unsigned int height);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

