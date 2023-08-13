#pragma once
#include <windows.h>
#include <stdint.h>

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

namespace SnekDraw {
// For the screen and drawing things to the screen, no game logic
class Draw {
public:
	Draw(unsigned short, unsigned short);

	unsigned const char m_char_snek = '@';
	unsigned const short m_hud_rows = 2;
	
	void DrawCharacter(char, COORD);
private:
	unsigned char m_print_char = ' ';
	
	unsigned short m_screen_colums;
	unsigned short m_screen_rows;

	HANDLE m_hConsole {};
	COORD m_cursor_pos = { 0, 0 };
	COORD m_return_position = {0, 0};
};
}