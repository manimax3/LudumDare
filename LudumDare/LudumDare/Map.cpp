#include "Map.h"



Map::Map()
{
}


Map::~Map()
{

}

void Map::load(thor::ResourceHolder<sf::Texture, std::string> &holder,
	           sf::Vector2u tileSize, const int *tileSet, unsigned int width, unsigned int height)
{
	//Get the sprites.png from the loader
	m_SpriteSheet = holder["sprites"];

	//Prework the Vertex Array
	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(width * height * 4);

	//Getting the TileID

	//Update ther Vertice array
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileID = tileSet[i + (j * width)];

			// current quad
			sf::Vertex* quad = &m_Vertices[(i + j * width) * 4];

			// set Vertex corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// set Texture corners
			quad[0].texCoords = sf::Vector2f(tileID * tileSize.x, 0);
			quad[1].texCoords = sf::Vector2f((tileID + 1) * tileSize.x, 0);
			quad[2].texCoords = sf::Vector2f((tileID + 1) * tileSize.x,tileSize.y);
			quad[3].texCoords = sf::Vector2f(tileID * tileSize.x, tileSize.y);
		}
}
void Map::load(thor::ResourceHolder<sf::Texture, std::string> &holder,
	sf::Vector2u tileSize, const std::vector<unsigned int> tiles, unsigned int width, unsigned int height)
{
	//Get the sprites.png from the loader
	m_SpriteSheet = holder["sprites"];

	//Prework the Vertex Array
	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(width * height * 4);

	//Getting the TileID

	//Update ther Vertice array
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileID = tiles[i + (j * width)];
			// current quad
			sf::Vertex* quad = &m_Vertices[(i + j * width) * 4];

			// set Vertex corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// set Texture corners
			quad[0].texCoords = sf::Vector2f(tileID * tileSize.x, 0);
			quad[1].texCoords = sf::Vector2f((tileID + 1) * tileSize.x, 0);
			quad[2].texCoords = sf::Vector2f((tileID + 1) * tileSize.x, tileSize.y);
			quad[3].texCoords = sf::Vector2f(tileID * tileSize.x, tileSize.y);
		}
}



void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	//states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_SpriteSheet;

	// draw the vertex array
	target.draw(m_Vertices, states);
}
