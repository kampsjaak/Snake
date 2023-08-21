#include <chrono> // random nummer generation
#include <algorithm>
#include <random>

#include "PlayArea.h"

Snek::PlayArea::PlayArea(unsigned short top, unsigned short left, unsigned short bottom, unsigned short right) {
	m_max_y = top;
	m_min_x = left;
	m_min_y = bottom;
	m_max_x = right;

	short rows = m_max_y - m_min_y;
	short columns = m_max_x - m_min_x;
	short vector_size = rows * columns;
	m_free_cells.resize(vector_size);

	for (auto i = 0; i < vector_size; i++) {
		m_free_cells[i].X = m_min_x + i % columns;
		m_free_cells[i].Y = m_min_y + floor(i / columns);
	}
};

void Snek::PlayArea::MoveSnek(COORD head, COORD tail) {
	short new_head_index = -1;
	for (short i = 0; i < m_free_cells.size(); i++) {
		if(m_free_cells[i].X == head.X && m_free_cells[i].Y == head.Y) {
			new_head_index = i;
			break;
		}
	}
	// FIXME:	if new_head_index evaluates as -1 or vector.size() == 0,
	//			we have won or touched ourselves.
	m_free_cells[new_head_index] = tail;

	new_head_index = -1;
	for (short i = 0; i < m_snake_cells.size(); i++) {
		if (m_snake_cells[i].X == tail.X && m_snake_cells[i].Y == tail.Y) {
			new_head_index = i;
			break;
		}
	}
	m_snake_cells[new_head_index] = head;
};

Snek::MoveResponse Snek::PlayArea::GrowSnek(COORD head) {
	short new_head_index = -1;
	for (auto i = 0; i < m_free_cells.size(); i++) {
		if (m_free_cells[i].X == head.X && m_free_cells[i].Y == head.Y) {
			new_head_index = i;
			break;
		}
	}
	if (new_head_index > -1) {
		m_free_cells.erase(m_free_cells.begin() + new_head_index);
		m_snake_cells.push_back(head);
		return MoveResponse::GROW;
	}
	else {
		bool touching = false;
		for (auto& coord : m_snake_cells) {
			if (coord.X == head.X && coord.Y == head.Y) {
				touching = true;
				break;
			}
		}
		return MoveResponse::TOUCH;
	}
	return MoveResponse::OUT_OF_BOUNDS;
};

std::vector<COORD> Snek::PlayArea::GetRandomFreePositions(unsigned short count) {
	auto size = m_free_cells.size();
	count < size ? true : count = size;
	
	std::vector<COORD> out_vector;
	// FIXME:	I'm sure I can do this in the constructor
	out_vector.resize(count);

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::vector<COORD> copy_vector = m_free_cells;
	std::shuffle(std::begin(copy_vector), std::end(copy_vector), std::default_random_engine(seed));
	
	for (auto i = 0; i < count; i++) {
		out_vector[i] = copy_vector[i];
	}

	return out_vector;
};