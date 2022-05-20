#include "Interface.h"

Interface::Interface() {
	return;
};

void Interface::DrawMainMenu(SnekManager& sm) {
	return;
};

void Interface::DrawGameOver() {
	return;
};

void Interface::DrawGameUI() {
	COORD a = {0, 0};
	COORD b = {0, m_snekManager->height};

	for (short i = 0; i <= m_snekManager->width; i++) {
		a.X = i;
		b.X = i;
		m_snekManager->GetDraw()->DrawCharacter('+', a);
		m_snekManager->GetDraw()->DrawCharacter('+', b);

	}
	return;
};

void Interface::UpdateGameUIScore(int score) {
	return;
};