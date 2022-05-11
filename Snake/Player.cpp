#include <vector>
#include <iostream>

#include "Player.h"
#include "Draw.h"

void Player::DrawMe(Draw d) {
	for (auto& coord : Player::snake) {
		d.DrawCharacter('!', coord);
	}
}

void Player::Initialise(Draw d) {
	/*Player::snake->at(0) = COORD({ 0, 0 });
	Player::snake->at(1) = COORD({ 1, 0 });
	Player::snake->at(2) = COORD({ 2, 0 });*/
	Player::m_draw = d;
	Player::alive = true;
	Player::m_heading = Heading::Right;
	Player::DrawMe(m_draw);
}

void Player::Move() {
	// cursor to head, draw blank
	m_draw.DrawCharacter(' ', snake.back());
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
	m_draw.DrawCharacter('!', snake.back());
	m_draw.DrawCharacter(' ', snake.front());
}

void Player::Redraw() { return; };

Player::Player() { return; };