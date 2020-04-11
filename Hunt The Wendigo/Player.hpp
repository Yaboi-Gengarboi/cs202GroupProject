// Player.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/13/2020
// Last updated on 3/14/2020

#include "Room.hpp"
// <memory>
// <array>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	// This shared_ptr will point to the player's current room.
	std::shared_ptr<Room> _currentRoom = nullptr;

	// The player will have health that can be depleted or
	// regenerated. If it reaches 0, then the player dies.
	// A health of -1 indicates an uninitialized health.
	int _health = -1;

	public:

	// Standard cinstructor.
	Player(const Room& currentRoom, int health);

	// Destructor.
	~Player();

	// Returns a shared_ptr to the player's current room.
	std::shared_ptr<Room> currentRoom() const;

	// Returns the player's health.
	int health() const;

	// Sets the shared_ptr of the player's current room
	// to point to room.
	void setCurrentRoom(const Room& room);

	// Subtracts health from the player's health.
	void damage(int health);

	// Adds health to the player's health.
	void heal(int health);
	
	

};

#endif // PLAYER_HPP