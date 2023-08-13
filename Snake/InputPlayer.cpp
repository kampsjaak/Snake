#include "InputPlayer.h"

Snek::InputPlayer::InputPlayer(Player* player) {
	m_player = player;
};

void Snek::InputPlayer::Update() {
	if (GetAsyncKeyState(0x41)) {
		if (m_player->m_previous_heading == Snek::Heading::Right) return;
		m_player->m_heading = Snek::Heading::Left;
		return;
	}
	else if (GetAsyncKeyState(0x44)) {
		if (m_player->m_previous_heading == Snek::Heading::Left) return;

		m_player->m_heading = Snek::Heading::Right;
		return;
	}
	else if (GetAsyncKeyState(0x57)) {
		if (m_player->m_previous_heading == Snek::Heading::Down) return;

		m_player->m_heading = Snek::Heading::Top;
		return;
	}
	else if (GetAsyncKeyState(0x53)) {
		if (m_player->m_previous_heading == Snek::Heading::Top) return;

		m_player->m_heading = Snek::Heading::Down;
		return;
	}
}