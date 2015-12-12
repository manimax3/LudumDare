#include "Map.h"



Map::Map()
{

}


Map::~Map()
{

}

void Map::load(const std::string& name, sf::Vector2u tileSize, const int tileID, unsigned int width, unsigned int height)
{
	//Loading the Textur
	if (!m_SpriteSheet.loadFromFile(name))
		std::cerr << "Failed to load Map! " << name << std::endl;

	//Prework the Vertex Array
	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(width * height * 4);

	//Adding the tiles based on the tileset to the array
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number

			// find its position in the tileset texture
			int tu = tileID % (m_SpriteSheet.getSize().x / tileSize.x);
			int tv = tileID / (m_SpriteSheet.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_Vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
}



void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_SpriteSheet;

	// draw the vertex array
	target.draw(m_Vertices, states);
}
