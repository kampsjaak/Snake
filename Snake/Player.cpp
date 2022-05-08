#include "Player.h"
#include <vector>
#include <iostream>

void Player::Initialise() {
	Player::alive = true;
	Player::m_head = { 1,1 };
	Player::m_heading = Heading::Right;
	std::cout << "init!";
}

Player::Player() { return; };