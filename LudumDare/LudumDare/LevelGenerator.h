#pragma once
#include <vector>
#include <Thor\Math.hpp>

enum class LevelType {RANDOM, STANDARD};
class LevelGenerator
{
private:
	unsigned int sprite_range, width, height;
	LevelType type;
public:
	LevelGenerator(LevelType type, unsigned int sprite_range, unsigned int width, unsigned int height);
	~LevelGenerator();

	std::vector<unsigned int> generateLevel();
	inline void changeType(LevelType t) { type = t; }
};

