#include "Player.h"
#include <vector>
#include <iostream>

void Player::Initialise() {
	Player::alive = true;
	Player::m_heading = Heading::Right;
	std::cout << "init player!";
}

void Player::Move() {
	switch (m_heading) {
	case Heading::Left:
		m_head.X = snake->back().X - 1;
		m_head.Y = snake->back().Y;
		break;
	case Heading::Right:
		m_head.X = snake->back().X + 1;
		m_head.Y = snake->back().Y;
		break;
	case Heading::Top:
		m_head.X = snake->back().X;
		m_head.Y = snake->back().Y + 1;
		break;
	case Heading::Down:
		m_head.X = snake->back().X;
		m_head.Y = snake->back().Y - 1;
		break;
	}
}

void Player::Draw() {
	for (auto& segment : Player::snake) {

	}
}

Player::Player() { return; };