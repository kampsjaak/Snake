#include <stdint.h>
#include <iostream>

#include "DrawConsole.h"

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

SnekDraw::DrawConsole::DrawConsole(const unsigned short width, const unsigned short height) {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_screen_colums = width;
	m_screen_rows = height;
};

void SnekDraw::DrawConsole::DrawCharacter(const GameCharacter character, const COORD position) {
	if (position.X < 0 || position.X > m_screen_colums) return;
	if (position.Y < 0 || position.Y > m_screen_rows) return;

	switch (character) {
		case GameCharacter::EMPTY:
			m_print_char = ' ';
			break;
		case GameCharacter::SNAKE:
			m_print_char = '@';
			break;
		case GameCharacter::APPLE:
			m_print_char = 'o';
			break;
		case GameCharacter::HORIZONTAL_BORDER:
			m_print_char = '+';
			break;
		case GameCharacter::VERTICAL_BORDER:
			m_print_char = '~';
			break;
		default:
			m_print_char = '?';
			break;
	}	
	SetConsoleCursorPosition(m_hConsole, position);
	WriteConsole(m_hConsole, &m_print_char, 1, NULL, NULL);
	SetConsoleCursorPosition(m_hConsole, m_return_position);
};