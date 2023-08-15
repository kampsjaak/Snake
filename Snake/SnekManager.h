#pragma once 
#include <stdint.h>

#include "Draw.h"
#include "UI.h"
#include "Game.h"

namespace Snek {

	// house all globals here
class SnekManager {
public:
	SnekManager(SnekDraw::Draw*, UI*);
	SnekDraw::Draw* GetDraw() { return m_draw; };
	UI* GetUI() { return m_ui; };
	void CreateGame();
	Game* GetGame() { return &m_game; };
	Player* GetPlayer() { return &m_player; };
private:
	Game m_game;
	Player m_player;
	UI* m_ui;
	SnekDraw::Draw* m_draw;
};
}