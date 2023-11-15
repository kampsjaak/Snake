#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime> // random nummer generation
#include <vector>

#include "Game.h"
#include "SnekManager.h"
#include "Draw.h"
#include "Player.h"

COORD Snek::Game::RandomPosition() {
	auto rng = static_cast<short>(rand());
	return { static_cast<short>(rng % m_snekManager->GetUI()->Width()),
		static_cast<short>(rng % m_snekManager->GetUI()->Height())
		};
}

void Snek::Game::SpawnApple(COORD* apple, COORD pos) {
	apple->X = pos.X;
	apple->Y = pos.Y;
	m_snekManager->GetDraw()->DrawCharacter(SnekDraw::GameCharacter::APPLE, *apple);
	return;
}

void Snek::Game::SpawnApple() {
	// FIXME:	Do something more intelligent
	//			Should there be a world and apple manager?
	SpawnApple(&m_apples[0], RandomPosition());
}

void Snek::Game::SpawnApples() {
	for(auto i = 0; i < m_apple_spawn_count; i++) {
		m_snekManager->GetDraw()->DrawCharacter(SnekDraw::GameCharacter::APPLE, m_apples[i]);
	}
}

//bool Snek::Game::PlayerOutOfBounds(Player* player) {
//	COORD* head = &player->m_snake.back();
//	if (	head->X < 0
//		||	head->Y < m_snekManager->GetUI()->m_hud_bottom_rows
//		||	head->X > m_snekManager->GetUI()->Width()
//		||	head->Y > m_snekManager->GetUI()->Height()) {
//		return true;
//	}
//	return false;
//}
//
//bool Snek::Game::PlayerTouchesSelf(Player* player) {
//	if (player->IsAtPosition(player->m_snake.back())) return true;
//	return false;
//};

void Snek::Game::Initialize(SnekManager* sm, Player* player) {
	// initialise dependencies
	srand(static_cast<unsigned int>(time(0)));

	// member variable assignment
	m_snekManager = sm;
	m_player = player;
	m_input_player = InputPlayer(m_player);
	m_localisation = Localisation();
	m_play_area = PlayArea(
		m_snekManager->GetUI()->m_hud_top_rows,
		m_snekManager->GetUI()->m_border_column,
		m_snekManager->GetUI()->Height() - m_snekManager->GetUI()->m_hud_bottom_rows,
		m_snekManager->GetUI()->Width() - m_snekManager->GetUI()->m_border_column);

	// initialise gameplay systems
	m_snekManager->GetUI()->DrawGameUI(m_snekManager->GetDraw(), Game::GetScore(), Game::GetLives(), GetLocalisation());
	m_player->Initialise(&m_play_area, { { 1,5 }, { 2,5 }, { 3,5 } }, Heading::Right);
	m_apples = m_play_area.GetRandomFreePositions(m_apple_spawn_count);
	SpawnApple();
}

// Move this to PlayArea class and check for apples during MoveStat checks
bool Snek::Game::CheckCollisions() {
	bool redraw = false;
	for (auto& apple : m_apples) {
		if (m_player->m_head.X == apple.X && m_player->m_head.Y == apple.Y) {
			redraw = true;
			// NOTE:	Fix specific apple respawning
			//SpawnApple(); 
		}
	}
	return redraw;
}

void Snek::Game::Update() {
	m_input_player.Update();
	m_player->Move([&](COORD head, COORD tail) {
		auto move_response = m_play_area.CheckCollisions(head, tail);
		switch (move_response) {
			case MoveState::OUT_OF_BOUNDS:
				m_game_state = GameState::GAME_OVER_OUT_OF_BOUNDS;
				return;
			case MoveState::TOUCH_SELF:
				m_game_state = GameState::GAME_OVER_TOUCH_SELF;
				return;
			case MoveState::MOVE:
				m_player->Redraw(false);
				return;
			case MoveState::GROW:
				m_player->Redraw(true);
				return;
			default:
				break;
			}
		});
}
