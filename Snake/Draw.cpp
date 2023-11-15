#include "Draw.h"

SnekDraw::Draw::Draw(const unsigned short width, const unsigned short height) {
	m_screen_colums = width;
	m_screen_rows = height;
};

void SnekDraw::Draw::DrawCharacter(GameCharacter character, COORD position) {
	m_print_char = '!';
};