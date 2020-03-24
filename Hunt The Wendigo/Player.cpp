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

Player::Player() {}

Player::Player(const Room& currentRoom, int health)
{

}

Player::~Player() {}

shared_ptr<Room> Player::currentRoom() const
{
	return _currentRoom;
}

int Player::health() const
{
	return _health;
}

void Player::setCurrentRoom(const Room& room)
{
	_currentRoom = make_shared<Room>(room);
}

void Player::damage(int health)
{
	_health -= health;
}

void Player::heal(int health)
{
	_health += health;
}