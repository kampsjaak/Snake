#include <vector>
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "SnekManager.h"
#include "Draw.h"

void Snek::Player::DrawSelf() {
	SnekDraw::Draw* draw = m_snek_manager->GetDraw();
	for (auto& coord : Player::m_snake) {
		draw->DrawCharacter(SnekDraw::GameCharacter::SNAKE, coord);
	}
}

bool Snek::Player::IsAtPosition(COORD point) {
	for (auto& coord : Player::m_snake) {
		if (coord.X == point.X && coord.Y == point.Y) return true;
	}
	return false;
}

void Snek::Player::Redraw(bool grow) {
	// undraw the tail
	SnekDraw::Draw* draw = m_snek_manager->GetDraw();
	draw->DrawCharacter(SnekDraw::GameCharacter::EMPTY, m_snake.front());

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

	draw->DrawCharacter(SnekDraw::GameCharacter::SNAKE, m_snake.back());
	return;
};

void Snek::Player::Initialise(std::vector<COORD> snake, Heading h) {
	m_snake = snake;
	m_heading = Heading::Right;
	DrawSelf();
}

void Snek::Player::Move() {
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

Snek::Player::Player(SnekManager* snek_manager) {
	m_snek_manager = snek_manager;
};