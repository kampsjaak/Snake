#pragma once
#include "Draw.h"

namespace SnekDraw {
class DrawConsole : public Draw {
public:
	DrawConsole(unsigned short, unsigned short);
	void DrawCharacter(GameCharacter, Snek::Coord) override;
private:
	unsigned char m_print_char = ' ';
	unsigned short m_screen_colums;
	unsigned short m_screen_rows;

	HANDLE m_hConsole{};
	//Snek::Coord m_cursor_pos = { 0, 0 };
	Snek::Coord m_return_position = { 0, 0 };
};
}
