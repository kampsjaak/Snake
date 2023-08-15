#include <ctime> // random nummer generation

#include "PlayArea.h"

Snek::PlayArea::PlayArea(unsigned short top, unsigned short left, unsigned short bottom, unsigned short right) {
	m_max_y = top;
	m_min_x = left;
	m_min_y = bottom;
	m_max_x = right;

	short vector_size = (m_max_y - m_min_y) * (m_max_x - m_min_x);
	m_free_cells.resize(vector_size);
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

void Snek::PlayArea::GrowSnek(COORD head) {
	short new_head_index = -1;
	for (short i = 0; i < m_free_cells.size(); i++) {
		if (m_free_cells[i].X == head.X && m_free_cells[i].Y == head.Y) {
			new_head_index = i;
			break;
		}
	}
	
	m_free_cells.erase(m_free_cells.begin() + new_head_index);
	m_snake_cells.insert(m_snake_cells.begin(), head);
};

std::vector<COORD> Snek::PlayArea::GetRandomFreePositions(unsigned short count) {
	std::vector<COORD> out_vector;
	// FIXME:	I'm sure I can do this in the constructor
	out_vector.resize(count);

	short divisor = m_free_cells.size();
	srand(static_cast<unsigned int>(time(0)));;
	short random_number = static_cast<short>(rand());

	for (auto  &coord : out_vector) {
		coord = m_free_cells[random_number % divisor];
	}

	return out_vector;
};