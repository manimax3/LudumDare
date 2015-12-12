#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Variables.h"
class Map : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture m_SpriteSheet;
	sf::VertexArray m_Vertices;
public:
	Map();
	~Map();
	void load(const std::string& name, sf::Vector2u tileSize, const int tileID, unsigned int width, unsigned int height);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
