#include <chrono> // random nummer generation
#include <algorithm>
#include <random>

#include "PlayArea.h"

Snek::PlayArea::PlayArea(unsigned short top, unsigned short left, unsigned short bottom, unsigned short right) {
	// NOTE:	absolute coordinates, portion of CLI::WIDTH and CLI::HEIGHT
	m_min_y = top;
	m_min_x = left;
	m_max_y = bottom;
	m_max_x = right;

	short rows = m_max_y - m_min_y;
	short columns = m_max_x - m_min_x;
	short vector_size = rows * columns;
	m_free_cells.resize(vector_size);
	m_free_cells.reserve(vector_size);

	for (auto i = 0; i < vector_size; i++) {
		m_free_cells[i].X = m_min_x + i % columns;
		m_free_cells[i].Y = m_min_y + static_cast<short>(floor(i / columns));
	}

	m_snake_cells.reserve(vector_size);
};

void Snek::PlayArea::MoveSnek(const COORD head) {
	short new_head_index = -1;
	for (short i = 0; i < m_free_cells.size(); i++) {
		if(m_free_cells[i].X == head.X && m_free_cells[i].Y == head.Y) {
			new_head_index = i;
			break;
		}
	}
	if (new_head_index < 0) return;

	m_free_cells.push_back(m_snake_cells[0]);	
	m_snake_cells.erase(m_snake_cells.begin());	
	m_snake_cells.push_back(m_free_cells[new_head_index]);
	m_free_cells.erase(m_free_cells.begin() + new_head_index);
};

bool Snek::PlayArea::IsAppleCell(const COORD new_head) {
	if (m_apple_cells.size() == 0) {
		return false;
	}

	for (COORD& cell: m_apple_cells) {
		if (cell.X == new_head.X && cell.Y == new_head.Y) {
			return true;
		}
	}
	return false;
}

Snek::Collision Snek::PlayArea::CheckCollisions(const COORD new_head) {
	short new_head_index = -1;

	// is new head a free cell?
	for (auto i = 0; i < m_free_cells.size(); i++) {
		if (m_free_cells[i].X == new_head.X && m_free_cells[i].Y == new_head.Y) {
			new_head_index = i;
			break;
		}
	}
		
	if (new_head_index < 0) {
		for (unsigned int i = 0; i < m_snake_cells.size() - 1; i++) {
			if (m_snake_cells[i].X == new_head.X && m_snake_cells[i].Y == new_head.Y) {
				return Collision::TOUCH_SELF;
			}
		}
		return Collision::OUT_OF_BOUNDS;
	} else {
		if (IsAppleCell(new_head)) {
			return Collision::GROW;
		}
		return Collision::NONE;
	}
};

std::vector<COORD> Snek::PlayArea::GetRandomFreePositions(unsigned short requested_number_of_positions, const COORD* excluded_position) {
	auto number_of_free_cells = m_free_cells.size();
	requested_number_of_positions < number_of_free_cells ? true : requested_number_of_positions = number_of_free_cells;

	std::vector<COORD> random_positions(requested_number_of_positions);

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::vector<COORD> shuffled_free_cells = m_free_cells;
	std::shuffle(std::begin(shuffled_free_cells), std::end(shuffled_free_cells), std::default_random_engine(seed));
	
	// the case that we have > 1 apple positions
	// we want to keep the existing positions but reroll the cooordinate at positional argument
	// while also excluding it as a potential new apple spot 
	if (excluded_position != nullptr) {
		for (auto i = shuffled_free_cells.size() - 1; i >= 0; i--) {
			if (shuffled_free_cells[i].X == excluded_position->X && shuffled_free_cells[i].Y == excluded_position->Y) {
				shuffled_free_cells.erase(shuffled_free_cells.begin() + i);
				break;
			}
		}
	}

	for (auto i = 0; i < requested_number_of_positions; i++) {
		random_positions[i] = shuffled_free_cells[i];
	}

	return random_positions;
};