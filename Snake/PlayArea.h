#pragma once
#include <vector>

#include "Coord.h"

namespace Snek {
enum class Collision : unsigned short {
	NONE,
	GROW,
	OUT_OF_BOUNDS,
	TOUCH_SELF
};
class PlayArea
{
public:
	PlayArea() {};
	PlayArea(unsigned short, unsigned short, unsigned short, unsigned short);

	void MoveSnek(const Snek::Coord);
	Collision CheckCollisions(Snek::Coord);
	bool IsAppleCell(const Snek::Coord);
	std::vector<Snek::Coord> GetRandomFreePositions(unsigned short, const Snek::Coord*);
	std::vector<Snek::Coord> m_snake_cells;
	std::vector<Snek::Coord> m_free_cells;
	std::vector<Snek::Coord> m_apple_cells = {};
private:
	unsigned short m_max_y = 0;
	unsigned short m_min_x = 0;
	unsigned short m_min_y = 0;
	unsigned short m_max_x = 0;
};
}
