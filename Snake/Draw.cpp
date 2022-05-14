#include <windows.h>
#include <stdint.h>

#include "Draw.h"

Draw::Draw(uint32_t width, uint32_t height) {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_screenColums = width;
	m_screenRows = height;
};

void Draw::DrawCharacter(const char character, COORD position) { 
	m_printChar = character;
	if (position.X < 0 || position.X > m_screenColums) return;
	if (position.Y < 0 || position.Y > m_screenRows) return;
	SetConsoleCursorPosition(m_hConsole, position);
	WriteConsole(m_hConsole, &m_printChar, 1, NULL, NULL);
	SetConsoleCursorPosition(m_hConsole, m_returnPosition);
};