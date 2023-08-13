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
	enum class GameCharacter {
		EMPTY,
		SNAKE,
		APPLE,
		HORIZONTAL_BORDER,
		VERTICAL_BORDER
	};

// For the screen and drawing things to the screen, no game logic
class Draw {
public:
	Draw() {};
	Draw(unsigned short, unsigned short);

	unsigned const char m_char_snek = '@';
	unsigned const short m_hud_rows = 2;
	
	virtual void DrawCharacter(GameCharacter, COORD);
private:
	unsigned char m_print_char = ' ';
	unsigned short m_screen_colums = 0;
	unsigned short m_screen_rows = 0;

	
};
}