#include "Draw.h"
#include <windows.h>
#include "Draw.h"

Draw::Draw(unsigned short width, unsigned short height) {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw::m_screenColums = width;
	Draw::m_screenRows = height;
};

void Draw::DrawCharacter(const char* character, COORD position) { 
	if (position.X < 0 || position.X > m_screenColums) return;
	if (position.Y < 0 || position.Y > m_screenRows) return;
	SetConsoleCursorPosition(m_hConsole, position);
	WriteConsole(m_hConsole, character, 1, NULL, NULL);
};