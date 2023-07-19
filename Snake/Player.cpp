#include <vector>
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "SnekManager.h"
#include "Draw.h"

void Player::DrawSelf() {
	unsigned char snekChar = m_snek_manager->GetDraw()->m_char_snek;
	Draw* draw = m_snek_manager->GetDraw();
	for (auto& coord : Player::m_snake) {
		draw->DrawCharacter(draw->m_char_snek, coord);
	}
}

bool Player::IsAtPosition(COORD point) {
	for (auto& coord : Player::m_snake) {
		if (coord.X == point.X && coord.Y == point.Y) return true;
	}
	return false;
}

void Player::Redraw(bool grow) {
	// undraw the tail
	Draw* draw = m_snek_manager->GetDraw();
	draw->DrawCharacter(' ', m_snake.front());

	// snek eat apple
	if(grow) {
		m_snake.push_back(m_head);
	} else {
		// shift array over 1 overwriting the tail
		for (size_t i = 0; i < m_snake.size() - 1; i++) {
			m_snake[i].X = m_snake[i + 1].X;
			m_snake[i].Y = m_snake[i + 1].Y;
		}
		// add head position
		m_snake.back() = m_head;
	}

	draw->DrawCharacter(draw->m_char_snek, m_snake.back());
	return;
};

void Player::Initialise(std::vector<COORD> snake, Heading h) {
	m_snake = snake;
	m_heading = Heading::Right;
	DrawSelf();
}

void Player::Move() {
	m_previous_heading = m_heading;
	switch (m_heading) {
	case Heading::Left:
		m_head.X = m_snake.back().X - 1;
		m_head.Y = m_snake.back().Y;
		break;
	case Heading::Right:
		m_head.X = m_snake.back().X + 1;
		m_head.Y = m_snake.back().Y;
		break;
	case Heading::Top:
		m_head.X = m_snake.back().X;
		m_head.Y = m_snake.back().Y - 1;
		break;
	case Heading::Down:
		m_head.X = m_snake.back().X;
		m_head.Y = m_snake.back().Y + 1;
		break;
	}
}

Player::Player(SnekManager* snek_manager) {
	m_snek_manager = snek_manager;
};