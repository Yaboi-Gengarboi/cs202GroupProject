// Player.cpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/14/2020
// Last updated on 3/14/2020

#include "Player.hpp"
// "Room.hpp"
// <memory>
// <array>

using std::shared_ptr;
using std::make_shared;

Player::Player(int health)
{
	
}

Player::~Player() {}

std::pair<int, int> Player::getPosition() const
{
	return _position;
}

int Player::health() const
{
	return _health;
}

void Player::setPosition(int x, int y)
{
	_position = std::pair<int, int>(x, y);
}

void Player::damage(int health)
{
	_health -= health;
}

void Player::heal(int health)
{
	_health += health;
}

void Player::setHealth(int health) {
	_health = health;
}
