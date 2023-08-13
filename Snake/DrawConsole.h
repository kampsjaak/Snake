#pragma once
#include "Draw.h"

namespace SnekDraw {
class DrawConsole : public Draw {
public:
	DrawConsole(unsigned short, unsigned short);
	void DrawCharacter(GameCharacter, COORD) override;
private:
	unsigned char m_print_char = ' ';
	unsigned short m_screen_colums;
	unsigned short m_screen_rows;

	HANDLE m_hConsole{};
	//COORD m_cursor_pos = { 0, 0 };
	COORD m_return_position = { 0, 0 };
};
}