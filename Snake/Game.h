#pragma once
#include <vector>

#include "Coord.h"
#include "Player.h"
#include "Enums.h"
#include "Localisation.h"
#include "InputPlayer.h"
#include "PlayArea.h"

namespace Snek {
class SnekManager;

	class Game {
	public:
		Game() {};

		void Initialize(SnekManager*, Player*);
		void Update();
		void InitializeApples();

		PlayArea* GetPlayArea() { return &m_play_area; };
		Localisation* GetLocalisation() { return &m_localisation; };
		unsigned int GetScore() { return m_score; };
		unsigned short GetLives() { return m_lives; };

		PlayArea m_play_area;
		GameState m_game_state = GameState::RUNNING;

		SnekManager* m_snekManager{};
		Player* m_player{};
	private:
		Localisation m_localisation;
		InputPlayer m_input_player;
		
		int SetAppleCount();
		void RespawnApple(const Snek::Coord);

		unsigned int m_score = 0;
		unsigned short m_lives = 3;
	};
}
