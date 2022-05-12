#pragma once
#include <windows.h>
#include <vector>
#include <string>

#include "Draw.h"

enum class Heading {
	Top,
	Down,
	Left,
	Right
};

class Player {
public:
	Player(Draw* d);

	void Initialise();
	void Move();
	void DrawMe();
	void Redraw();
	
	bool alive = false;
	std::vector<COORD> snake{{ 0,5 }, { 1,5 }, { 2,5 }};
	Heading m_heading = Heading::Left;
	COORD m_head = { -1,-1 };

private:
	Draw* m_draw;
};