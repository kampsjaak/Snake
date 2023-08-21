#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <functional>

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

	void Initialise(PlayArea*, std::vector<COORD>, Heading);
	void Move(std::function<void(COORD, COORD)>);
	void DrawSelf();
	void Redraw(bool);
	bool IsAtPosition(COORD);
	
	Heading m_heading = Heading::Right;
	Heading m_previous_heading = Heading::Right;
	
	COORD m_head = { -1,-1 };
	//std::vector<COORD> m_snake;
private:
	SnekManager* m_snek_manager = {};
	PlayArea* m_play_area = {};
};
}