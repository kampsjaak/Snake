#include <vector>
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "SnekManager.h"
#include "Draw.h"

void Snek::Player::DrawSelf() {
	SnekDraw::Draw* draw = m_snek_manager->GetDraw();
	for (auto& coord : m_play_area->m_snake_cells) {
		draw->DrawCharacter(SnekDraw::GameCharacter::SNAKE, coord);
	}
}

bool Snek::Player::IsAtPosition(COORD point) {
	for (auto& coord : m_play_area->m_snake_cells) {
		if (coord.X == point.X && coord.Y == point.Y) return true;
	}
	return false;
}

void Snek::Player::Redraw(const bool grow) {
	// undraw the tail
	SnekDraw::Draw* draw = m_snek_manager->GetDraw();
	draw->DrawCharacter(SnekDraw::GameCharacter::EMPTY, m_play_area->m_snake_cells.front());

	// snek eat apple
	if(grow) {
		m_play_area->m_snake_cells.push_back(m_head);
	} else {
		// shift array over 1 overwriting the tail
		for (size_t i = 0; i < m_play_area->m_snake_cells.size() - 1; i++) {
			m_play_area->m_snake_cells[i].X = m_play_area->m_snake_cells[i + 1].X;
			m_play_area->m_snake_cells[i].Y = m_play_area->m_snake_cells[i + 1].Y;
		}
		// add head position
		m_play_area->m_snake_cells.back() = m_head;
	}

	draw->DrawCharacter(SnekDraw::GameCharacter::SNAKE, m_play_area->m_snake_cells.back());
	return;
};

void Snek::Player::Initialise(PlayArea* play_area, std::vector<COORD> snake, Heading h) {
	m_play_area = play_area;
	for (auto& cell : snake) {
		m_play_area->m_snake_cells.push_back(cell);
	}
	
	m_heading = Heading::Right;
	DrawSelf();
}

void Snek::Player::Move(std::function<void(COORD, COORD)> Callback) {
	COORD tail = m_play_area->m_snake_cells[0];

	m_previous_heading = m_heading;
	switch (m_heading) {
	case Heading::Left:
		m_head.X = m_play_area->m_snake_cells.back().X - 1;
		m_head.Y = m_play_area->m_snake_cells.back().Y;
		break;
	case Heading::Right:
		m_head.X = m_play_area->m_snake_cells.back().X + 1;
		m_head.Y = m_play_area->m_snake_cells.back().Y;
		break;
	case Heading::Top:
		m_head.X = m_play_area->m_snake_cells.back().X;
		m_head.Y = m_play_area->m_snake_cells.back().Y - 1;
		break;
	case Heading::Down:
		m_head.X = m_play_area->m_snake_cells.back().X;
		m_head.Y = m_play_area->m_snake_cells.back().Y + 1;
		break;
	}
	Callback(m_play_area->m_snake_cells.back(), tail);
}

void Snek::Player::SetSnekManager(SnekManager* snek_manager) {
	m_snek_manager = snek_manager;
};
