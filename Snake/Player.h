#pragma once
#include <windows.h>
#include <vector>
enum Heading {
	Top,
	Down,
	Left,
	Right
};
class Player {
public:
	Player();
	Heading heading;
	COORD head;
	std::vector<COORD> snake[3];
	bool alive;
private:
};