#include "SnekManager.h"

Snek::SnekManager::SnekManager(SnekDraw::Draw* d, UI* i) {
	m_draw = d;
	m_ui = i;
	m_player.SetSnekManager(this);
	CreateGame();
};

void Snek::SnekManager::CreateGame() {
	m_game.Initialize(this, GetPlayer());
};