#include <vector>
#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Draw.h"
#include "SnekManager.h"

void Player::DrawSelf() {
	for (auto& coord : Player::snake) {
		m_snekManager->GetDraw()->DrawCharacter('!', coord);
	}
}

void Player::Redraw() {
	// undraw the tail bit
	// shift array over 1 overwriting the tail
	// add head position

	// add state for growing the snek

	return;
};

void Player::Initialise() {
	Player::m_heading = Heading::Right;
	Player::DrawSelf();
}

void Player::Move() {
	// cursor to head, draw blank
	m_snekManager->GetDraw()->DrawCharacter(' ', snake.back());
	switch (m_heading) {
	case Heading::Left:
		m_head.X = snake.back().X - 1;
		m_head.Y = snake.back().Y;
		break;
	case Heading::Right:
		m_head.X = snake.back().X + 1;
		m_head.Y = snake.back().Y;
		break;
	case Heading::Top:
		m_head.X = snake.back().X;
		m_head.Y = snake.back().Y + 1;
		break;
	case Heading::Down:
		m_head.X = snake.back().X;
		m_head.Y = snake.back().Y - 1;
		break;
	}
	m_snekManager->GetDraw()->DrawCharacter('!', snake.back());
	m_snekManager->GetDraw()->DrawCharacter(' ', snake.front());
}

Player::Player(SnekManager* sm) {
	m_snekManager = sm;
};