#include <stdint.h>
#include <iostream>

#include "Draw.h"

Draw::Draw() {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//uint32_t Draw::m_screen_colums = width;
	//uint32_t Draw::m_screen_rows = height;
};

void Draw::DrawCharacter(const char character, COORD position) { 
	m_print_char = character;
	if (position.X < 0 || position.X > m_screen_colums) return;
	if (position.Y < 0 || position.Y > m_screen_rows) return;
	SetConsoleCursorPosition(m_hConsole, position);
	WriteConsole(m_hConsole, &m_print_char, 1, NULL, NULL);
	SetConsoleCursorPosition(m_hConsole, m_return_position);
};