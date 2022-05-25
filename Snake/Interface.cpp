#include "Interface.h"

Interface::Interface() {
	return;
};

void Interface::DrawMainMenu(SnekManager* sm) {
	return;
};

void Interface::DrawGameOver(SnekManager* sm) {
	return;
};

void Interface::DrawGameUI(SnekManager* sm) {
	COORD a = {0, 0};
	COORD b = {0, sm->height};

	for (short i = 0; i <= sm->width; i++) {
		a.X = i;
		b.X = i;
		sm->GetDraw()->DrawCharacter('+', a);
		sm->GetDraw()->DrawCharacter('+', b);

	}
	return;
};

void Interface::UpdateGameUIScore(int score) {
	return;
};