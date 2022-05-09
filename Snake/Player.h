#pragma once
#include <windows.h>
#include <vector>

enum class Heading {
	Top,
	Down,
	Left,
	Right
};

class Player {
public:
	Player();
	void Initialise();
	void Move();
	void Draw();
	void Redraw();
	Heading m_heading = Heading::Left;
	COORD m_head = {-1,-1};
	std::vector<COORD> snake[3];
	bool alive = false;
private:
};