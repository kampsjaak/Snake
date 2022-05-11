#include <vector>
#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Draw.h"

void Player::DrawMe(Draw* d) {
	for (auto& coord : Player::snake) {
		m_draw->DrawCharacter('!', coord);
	}
}

void Player::Initialise() {
	Player::m_heading = Heading::Right;
	
	//Player::DrawMe(m_draw);
}

void Player::Move() {
	// cursor to head, draw blank
	m_draw->DrawCharacter(' ', snake.back());
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
	m_draw->DrawCharacter('!', snake.back());
	m_draw->DrawCharacter(' ', snake.front());
}

void Player::Redraw() { 
	// undraw the tail bit
	// shift array over 1 overwriting the tail
	// add head position

	// add state for growing the snek

	return; 
};

//Player::Player() { 
//	return;
//};