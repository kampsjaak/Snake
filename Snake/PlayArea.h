#pragma once
#include <windows.h>
#include <vector>

namespace Snek {
enum class MoveResponse : unsigned short {
	GROW,
	OUT_OF_BOUNDS,
	TOUCH
};
class PlayArea
{
public:
	PlayArea() {};
	PlayArea(unsigned short, unsigned short, unsigned short, unsigned short);

	void MoveSnek(COORD, COORD);
	MoveResponse GrowSnek(COORD);
	std::vector<COORD> GetRandomFreePositions(unsigned short);
	//bool COORD IsCoordinateInBounds(COORD);
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