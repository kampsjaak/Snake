#pragma once
#include <windows.h>
#include <vector>


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
		void SpawnApple();
		void SpawnApple(COORD*, COORD);
		void SpawnApples();
		COORD RandomPosition();

		PlayArea* GetPlayArea() { return &m_play_area; };
		Localisation* GetLocalisation() { return &m_localisation; };
		unsigned int GetScore() { return m_score; };
		unsigned short GetLives() { return m_lives; };

		PlayArea m_play_area;
		GameState m_game_state = GameState::RUNNING;
		std::vector<COORD> m_apples;

		SnekManager* m_snekManager{};
		Player* m_player{};
	private:
		Localisation m_localisation;
		InputPlayer m_input_player;
		
		//bool PlayerOutOfBounds(Player*);
		//bool PlayerTouchesSelf(Player*);
		bool CheckCollisions();

		unsigned int m_score = 0;
		unsigned short m_lives = 3;
		unsigned short m_apple_spawn_count = 3;

	};
}