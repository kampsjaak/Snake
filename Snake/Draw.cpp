#include "Draw.h"
#include <windows.h>

Draw::Draw(unsigned short width, unsigned short height) {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw::m_screenColums = width;
	Draw::m_screenRows = height;
};

void Draw::DrawCharacter(const char character, COORD position) { 
	m_printChar = character;
	if (position.X < 0 || position.X > Draw::m_screenColums) return;
	if (position.Y < 0 || position.Y > Draw::m_screenRows) return;
	SetConsoleCursorPosition(Draw::m_hConsole, position);
	WriteConsole(Draw::m_hConsole, &m_printChar, 1, NULL, NULL);
};