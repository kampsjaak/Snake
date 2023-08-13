#pragma once
#include <windows.h>
#include <stdint.h>

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

	unsigned const short m_hud_rows = 2;
	
	virtual void DrawCharacter(GameCharacter, COORD);
private:
	unsigned char m_print_char = ' ';
	unsigned short m_screen_colums = 0;
	unsigned short m_screen_rows = 0;

	
};
}