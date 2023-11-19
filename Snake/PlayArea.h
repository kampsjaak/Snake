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
	bool IsAppleCell(const COORD);
	std::vector<COORD> GetRandomFreePositions(unsigned short, const COORD*);
	std::vector<COORD> m_snake_cells;
	std::vector<COORD> m_free_cells;
	std::vector<COORD> m_apple_cells = {};
private:
	unsigned short m_max_y = 0;
	unsigned short m_min_x = 0;
	unsigned short m_min_y = 0;
	unsigned short m_max_x = 0;
};
}