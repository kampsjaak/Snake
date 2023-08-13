#include <windows.h>
#include <iostream>

#include "UI.h"

void Snek::UI::DrawGameUI(SnekDraw::Draw* draw, unsigned int score, unsigned short lives, Localisation* localisation) {
	COORD line_0 = { 0, 0 };
	COORD line_1 = { 0, 1 };
	COORD line_2 = { 0, static_cast<short>(Height())};
	COORD line_3 = { static_cast<short>(Width()), 0};
	COORD line_4 = { 0, 0 };

	for (short i = 0; i <= Width(); i++) {
		line_0.X = i;
		line_1.X = i;
		line_2.X = i;
		draw->DrawCharacter('+', line_0);
		draw->DrawCharacter('+', line_1);
		draw->DrawCharacter('+', line_2);
	}
	for (short i = 2; i <= Height() - 1; i++) {
		line_3.Y = i;
		line_4.Y = i;
		draw->DrawCharacter('~', line_3);
		draw->DrawCharacter('~', line_4);
	}

	const std::string scoreboard_line_0 = localisation->GetString(Snek::LocalisedString::SCORE) + ": ";
	const std::string scoreboard_line_1 = localisation->GetString(Snek::LocalisedString::LIVES) + ": ";
	std::cout << scoreboard_line_0 << score << std::endl;
	std::cout << scoreboard_line_1 << lives << std::endl;
	return;
};

void Snek::UI::UpdateGameUIScore(int score) {
	return;
};