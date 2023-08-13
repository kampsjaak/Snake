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
	apple = &pos;
	m_snekManager->GetDraw()->DrawCharacter(SnekDraw::GameCharacter::APPLE, *apple);
	return;
}

void Snek::Game::SpawnApple() {
	// FIXME:	Do something more intelligent
	//			Should there be a world and apple manager?
	SpawnApple(&m_apples[0], RandomPosition());
}

bool Snek::Game::PlayerOutOfBounds(Player* player) {
	COORD* head = &player->m_snake.back();
	if (	head->X < 0
		||	head->Y < m_snekManager->GetDraw()->m_hud_rows
		||	head->X > m_snekManager->GetUI()->Width()
		||	head->Y > m_snekManager->GetUI()->Height()) {
		return true;
	}
	return false;
}

bool Snek::Game::PlayerTouchesSelf(Player* player) {
	if (player->IsAtPosition(player->m_snake.back())) return true;
	return false;
};

Snek::Game::Game(SnekManager* sm, Player* player) {
	// initialise dependencies
	srand(static_cast<unsigned int>(time(0)));

	// member variable assignment
	m_snekManager = sm;
	m_player = player;
	m_localisation = Localisation();

	//for (unsigned short x = 0; x < m_snekManager->m_width; x++) {
	//	for (unsigned short y = 0; y < m_snekManager->m_width; y++) {
	//		//m_play_area.insert
	//	}
	//}

	for (unsigned short i = 0; i < m_snekManager->GetUI()->Width() * m_snekManager->GetUI()->Height(); i++) {
		COORD c = { 
			i / m_snekManager->GetUI()->Width(),
			i % m_snekManager->GetUI()->Width()
		};
		freeSlots.insert(freeSlots.begin() + i, m_player->IsAtPosition(c));
	}

	// initialise gameplay systems
	m_snekManager->GetUI()->DrawGameUI(m_snekManager->GetDraw(), Game::GetScore(), Game::GetLives(), GetLocalisation());
	m_player->Initialise({ { 0,5 }, { 1,5 }, { 2,5 } }, Heading::Right);
	SpawnApple();

	return;
};

void Snek::Game::Update() {
	m_player->Move();
	if(m_player->m_head.X == m_apples[0].X && m_player->m_head.Y == m_apples[0].Y) {
		m_player->Redraw(true);
		SpawnApple();
	} else {
		m_player->Redraw(false);
	}
	if (PlayerOutOfBounds(m_player)) { 
		m_gameState = GameState::GAME_OVER;
		return; 
	};
	return;
}
