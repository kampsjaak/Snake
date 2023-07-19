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

class Draw {
public:
	Draw(uint32_t, uint32_t);

	unsigned char m_char_snek = '@';
	unsigned const short m_hud_rows = 2;
	
	void DrawCharacter(char, COORD);
	void DrawMainMenu();
	void DrawGameOver();
	void DrawGameUI(short, unsigned int, unsigned short);
	void UpdateGameUIScore(int);

private:
	unsigned char m_print_char = ' ';
	unsigned short m_screen_colums = 20;
	unsigned short m_screen_rows = 20;
	
	HANDLE m_hConsole {};
	COORD m_cursor_pos = { 0, 0 };
	COORD m_return_position = {0, 0};
};