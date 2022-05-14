#pragma once
#include <windows.h>
#include <vector>
#include <string>

#include "SnekManager.h"
#include "Draw.h"

enum class Heading {
	Top,
	Down,
	Left,
	Right
};

class Player {
public:
	Player(SnekManager*);

	void Initialise();
	void Move();
	void DrawSelf();
	void Redraw(bool);
	bool IsAtPosition(COORD);
	
	std::vector<COORD> snake{{ 0,5 }, { 1,5 }, { 2,5 }};
	Heading m_heading = Heading::Left;
	COORD m_head = { -1,-1 };
private:
	SnekManager* m_snekManager{};
};