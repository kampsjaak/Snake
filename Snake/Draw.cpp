#include "Draw.h"
#include <windows.h>

Draw::Draw(int window[2]) {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_screenColums = window[0];
	m_screenRows = window[1];
};

void Draw::DrawCharacter(const char character, COORD position) { 
	m_printChar = character;
	if (position.X < 0 || position.X > m_screenColums) return;
	if (position.Y < 0 || position.Y > m_screenRows) return;
	SetConsoleCursorPosition(m_hConsole, position);
	WriteConsole(m_hConsole, &m_printChar, 1, NULL, NULL);
};