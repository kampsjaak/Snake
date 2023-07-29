#include <windows.h>

#include "Interface.h"
#include "SnekManager.h"
#include "Draw.h"

Interface::Interface() {
	return;
};

void Interface::DrawMainMenu(SnekManager* sm) {
	return;
};

void Interface::DrawGameOver(SnekManager* sm) {
	return;
};

void Interface::DrawGameUI(SnekManager* snake_manager) {
	COORD a = {0, 0};
	COORD b = {0, snake_manager->height};

	for (short i = 0; i <= snake_manager->width; i++) {
		a.X = i;
		b.X = i;
		snake_manager->GetDraw()->DrawCharacter('+', a);
		snake_manager->GetDraw()->DrawCharacter('+', b);
	}
	return;
};

void Interface::UpdateGameUIScore(int score) {
	return;
};