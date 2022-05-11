#pragma once
#include <windows.h>
#include <vector>

#include "Draw.h"

enum class Heading {
	Top,
	Down,
	Left,
	Right
};

class Player {
public:
	Player();
	void Initialise(Draw d);
	void Move();
	void DrawMe(Draw d);
	void Redraw();
	Heading m_heading = Heading::Left;
	COORD m_head = { -1,-1 };
	std::vector<COORD> snake{{ 0,5 }, { 1,5 }, { 2,5 }};
	bool alive = false;
	Draw m_draw = Draw(0, 0);
private:
};