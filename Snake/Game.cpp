#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime> // random nummer generation
#include <vector>

#include "Game.h"
#include "SnekManager.h"
#include "Draw.h"
#include "Player.h"

int Snek::Game::SetAppleCount() {
	// TODO:	Determine the number of apples here dynamically
	int count = 3;
	m_play_area.m_apple_cells.resize(count);
	return count;
}

void Snek::Game::RespawnApple(const COORD old_apple) {
	for (COORD& cell : m_play_area.m_apple_cells) {
		if (cell.X == old_apple.X && cell.Y == old_apple.Y) {
			std::vector<COORD> new_apple = m_play_area.GetRandomFreePositions(1, &old_apple);
			cell.X = new_apple[0].X;
			cell.Y = new_apple[0].Y;
			m_snekManager->GetDraw()->DrawCharacter(SnekDraw::GameCharacter::APPLE, cell);
			break;
		}
	}
}

void Snek::Game::InitializeApples() {
	int count = SetAppleCount();
	std::vector<COORD> apples = m_play_area.GetRandomFreePositions(count, nullptr);
	m_play_area.m_apple_cells = apples;

;	for(auto i = 0; i < m_play_area.m_apple_cells.size(); i++) {
		m_snekManager->GetDraw()->DrawCharacter(SnekDraw::GameCharacter::APPLE, m_play_area.m_apple_cells[i]);
	}
}

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
	m_player->Initialise(&m_play_area, { { 1,2 }, { 2,2 }, { 3,2 } }, Heading::Right);
	InitializeApples();
}

void Snek::Game::Update() {
	m_input_player.Update();
	m_player->MoveHead([&](COORD new_head, COORD new_tail) {
		auto collision = m_play_area.CheckCollisions(new_head);
		COORD old_tail = m_play_area.m_snake_cells.front();
		switch (collision) {
			case Collision::OUT_OF_BOUNDS:
				m_game_state = GameState::GAME_OVER_OUT_OF_BOUNDS;
				return;
			case Collision::TOUCH_SELF:
				m_game_state = GameState::GAME_OVER_TOUCH_SELF;
				return;
			case Collision::NONE:
				m_play_area.MoveSnek(new_head);
				m_player->RedrawSelf(false, &old_tail);
				return;
			case Collision::GROW:
				m_play_area.MoveSnek(new_head);
				RespawnApple(new_head);
				m_player->RedrawSelf(true, nullptr);
				return;
			default:
				break;
			}
		});
}
