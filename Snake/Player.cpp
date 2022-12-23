#include <vector>
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "SnekManager.h"
#include "Draw.h"

void Player::DrawSelf() {
	unsigned char snekChar = m_snekManager->GetDraw()->m_charSnek;
	for (auto& coord : Player::snake) {
		m_snekManager->GetDraw()->DrawCharacter('@', coord);
	}
}

bool Player::IsAtPosition(COORD point) {
	for (auto& coord : Player::snake) {
		if (coord.X == point.X && coord.Y == point.Y) return true;
	}
	return false;
}

void Player::Redraw(bool grow) {
	// undraw the tail
	m_snekManager->GetDraw()->DrawCharacter(' ', snake.front());

	// snek eat apple
	if(grow) {
		snake.push_back(m_head);
	} else {
		// shift array over 1 overwriting the tail
		for (size_t i = 0; i < snake.size() - 1; i++) {
			snake[i].X = snake[i + 1].X;
			snake[i].Y = snake[i + 1].Y;
		}
		// add head position
		snake.back() = m_head;
	}

	m_snekManager->GetDraw()->DrawCharacter('@', snake.back());
	return;
};

void Player::Initialise(std::vector<COORD> _snake, Heading h) {
	snake = _snake;
	m_heading = Heading::Right;
	DrawSelf();
}

void Player::Move() {
	m_previousHeading = m_heading;
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
		m_head.Y = snake.back().Y - 1;
		break;
	case Heading::Down:
		m_head.X = snake.back().X;
		m_head.Y = snake.back().Y + 1;
		break;
	}
}

Player::Player(SnekManager* sm) {
	m_snekManager = sm;
};