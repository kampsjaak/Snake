#include <iostream>
#include <windows.h > // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#include <ctime>

#include "Game.h"

COORD Game::RandomPosition() {
	auto rng = static_cast<short>(rand());
	return { static_cast<short>(rng % m_snekManager->width),
		static_cast<short>(rng % m_snekManager->height)
		};
}

void Game::SpawnApple(COORD* apple, COORD pos) {
	apple = &pos;
	m_snekManager->GetDraw()->DrawCharacter('o', *apple);
	return;
}

void Game::SpawnApple() {
	// FIXME:	Do something more intelligent
	//			Should there be a world and apple manager?
	SpawnApple(&m_apples[0], RandomPosition());
}

bool Game::PlayerOutOfBounds(Player* player) {
	COORD* head = &player->snake.back();
	if (	head->X < 0
		||	head->Y < 0
		||	head->X > m_snekManager->width
		||	head->Y > m_snekManager->height) {
		return true;
	}
	return false;
}

bool Game::PlayerTouchesSelf(Player* player) {
	if (player->IsAtPosition(player->snake.back())) return true;
	return false;
};

Game::Game(SnekManager* sm, Player* player) {
	// initialise dependencies
	srand(static_cast<unsigned int>(time(0)));

	// member variable assignment
	m_snekManager = sm;
	m_player = player;

	// initialise gameplay systems
	//m_snekManager->GetInterface()->DrawGameUI(m_snekManager);
	m_player->Initialise({ { 0,5 }, { 1,5 }, { 2,5 } }, Heading::Right);
	SpawnApple();

	return;
};

void Game::Update() {
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
