#pragma once
#include <windows.h>

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
	Draw(unsigned short width, unsigned short height);
	void DrawCharacter(const char* character, COORD position);
private:
	unsigned short m_screenColums = 0;
	unsigned short m_screenRows = 0;
	HANDLE m_hConsole;
	COORD cursorPos = { 0, 0 };
	CONSOLE_CURSOR_INFO cursorInfo;

};