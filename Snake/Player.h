#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <functional>

namespace Snek {
	class SnekManager;

enum class Heading : unsigned short {
	Top,
	Down,
	Left,
	Right
};

class Player {
public:
	Player() {};

	void SetSnekManager(SnekManager*);
	void Initialise(std::vector<COORD>, Heading);
	void Move(std::function<void()>);
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