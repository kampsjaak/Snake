#include <windows.h>
#include <iostream>

#include "Interface.h"

Interface::Interface() {
	return;
};

void Interface::DrawMainMenu(Draw* sm) {
	return;
};

void Interface::DrawGameOver(Draw* sm) {
	return;
};

void Interface::DrawGameUI(Draw* draw, unsigned int score, unsigned short lives, Localisation* localisation) {
	COORD a = {0, 0};
	COORD b = {0, Draw::Height()};

	for (short i = 0; i <= Draw::Width(); i++) {
		a.X = i;
		b.X = i;
		draw->DrawCharacter('+', a);
		draw->DrawCharacter('+', b);
	}

	COORD line_0 = { 0, 0 };
	COORD line_1 = { 0, 1 };

	for (short i = 0; i <= Draw::Width(); i++) {
		line_0.X = i;
		line_1.X = i;
		draw->DrawCharacter('+', line_0);
		draw->DrawCharacter('+', line_1);
	}
	const std::string scoreboard_line_0 = localisation->GetString(LocalisedString::SCORE) + ": ";
	const std::string scoreboard_line_1 = localisation->GetString(LocalisedString::LIVES) + ": ";
	std::cout << scoreboard_line_0 << score << std::endl;
	std::cout << scoreboard_line_1 << lives << std::endl;
	return;
};

void Interface::UpdateGameUIScore(int score) {
	return;
};