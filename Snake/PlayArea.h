#pragma once
#include <windows.h>
#include <vector>

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

	void MoveSnek(const COORD);
	Collision CheckCollisions(COORD);
	std::vector<COORD> GetRandomFreePositions(unsigned short);
	std::vector<COORD> GetRandomFreePositions(unsigned short, std::vector<COORD>);
	std::vector<COORD> m_snake_cells;
	std::vector<COORD> m_free_cells;
private:
	// FIXME:	Make this _the_ snake instead
	
	unsigned short m_max_y = 0;
	unsigned short m_min_x = 0;
	unsigned short m_min_y = 0;
	unsigned short m_max_x = 0;
};
}