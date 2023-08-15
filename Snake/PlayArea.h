#pragma once
#include <windows.h>
#include <vector>

namespace Snek {
class PlayArea
{
public:
	PlayArea() {};
	PlayArea(unsigned short, unsigned short, unsigned short, unsigned short);

	void MoveSnek(COORD, COORD);
	void GrowSnek(COORD);
	std::vector<COORD> GetRandomFreePositions(unsigned short);
	//bool COORD IsCoordinateInBounds(COORD);
private:
	std::vector<COORD> m_snake_cells; // not _the_ snake
	std::vector<COORD> m_free_cells;
	
	// FIXME:	rename to min_x, etc
	unsigned short m_max_y = 0;
	unsigned short m_min_x = 0;
	unsigned short m_min_y = 0;
	unsigned short m_max_x = 0;
};
}