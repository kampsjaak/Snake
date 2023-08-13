#pragma once
#include <windows.h>
#include <vector>
#include <string>

#include "SnekManager.h"

namespace Snek {
enum class Heading : unsigned short {
	Top,
	Down,
	Left,
	Right
};

class Player {
public:
	Player() {};
	Player(SnekManager*);

	void Initialise(std::vector<COORD>, Heading);
	void Move();
	void DrawSelf();
	void Redraw(bool);
	bool IsAtPosition(COORD);
	
	Heading m_heading = Heading::Right;
	Heading m_previous_heading = Heading::Right;
	
	COORD m_head = { -1,-1 };
	std::vector<COORD> m_snake;
private:
	SnekManager* m_snek_manager = {};
};
}