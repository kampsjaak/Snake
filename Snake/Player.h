#pragma once
#include <vector>
#include <string>
#include <functional>

#include "Coord.h"

namespace Snek {
	class SnekManager;
	class PlayArea;

enum class Heading : unsigned short {
	Top,
	Down,
	Left,
	Right
};

enum class Redraw : unsigned short {
	REDRAW,
	REDRAW_AND_GROW
};

class Player {
public:
	Player() {};

	void SetSnekManager(SnekManager*);

	void Initialise(PlayArea*, std::vector<Snek::Coord>, Heading);
	void MoveHead(std::function<void(Snek::Coord, Snek::Coord)>);
	void DrawSelf();
	void RedrawSelf(bool, const Snek::Coord*);
	bool IsAtPosition(const Snek::Coord);
	
	Heading m_heading = Heading::Right;
	Heading m_previous_heading = Heading::Right;
	
	Snek::Coord m_head = { -1,-1 };
private:
	SnekManager* m_snek_manager = {};
	PlayArea* m_play_area = {};
};
}
