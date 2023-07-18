#include <windows.h>
#include <stdint.h>
#include <windows.h>
#include <iostream>

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

void Draw::DrawMainMenu() {
	return;
};

void Draw::DrawGameOver() {
	return;
};

void Draw::DrawGameUI(short width, unsigned int score, unsigned short lives) {
	COORD a = { 0, 0 };
	COORD b = { 0, 1 };

	for (short i = 0; i <= width; i++) {
		a.X = i;
		b.X = i;
		DrawCharacter('+', a);
		DrawCharacter('+', b);

	}
	const std::string scoreboard_line_0 = "Score: ";
	const std::string scoreboard_line_1 = "Lives: ";
	std::cout << scoreboard_line_0 << score << std::endl;
	std::cout << scoreboard_line_1 << lives << std::endl;
	return;
};

void Draw::UpdateGameUIScore(int score) {
	return;
};