#pragma once
#include <windows.h>
#include <vector>
#include <string>

#include "SnekManager.h"
#include "Draw.h"
#include "Enums.h"

class Player {
public:
	Player(SnekManager*);

	void Initialise(std::vector<COORD>, Heading);
	void Move();
	void DrawSelf();
	void Redraw(bool);
	bool IsAtPosition(COORD);
	
	std::vector<COORD> snake;
	Heading m_heading = Heading::Right;
	Heading m_previousHeading = Heading::Right;
	COORD m_head = { -1,-1 };
private:
	SnekManager* m_snekManager;
};