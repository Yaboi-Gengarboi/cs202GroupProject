// Player.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/13/2020
// Last updated on 3/14/2020

#include <map>
#include <memory>
#include <utility>
#include "Game.hpp"
#include "lib/tilemap.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	// The player will have health that can be depleted or
	// regenerated. If it reaches 0, then the player dies.
	// A health of -1 indicates an uninitialized health.
	int _health = -1;

	// The current position of the player in the world
	std::pair<int, int> _position{0, 0};

	// The inventory of the player. Stores items that they are currently holding.
	std::shared_ptr<std::map<int, int>> _inventory = std::make_shared<std::map<int, int>>();

	public:

	// Standard cinstructor.
	Player(const int health);

	// Destructor.
	~Player();

	// Returns a shared_ptr to the player's current room.
	std::pair<int, int> getPosition() const;

	// Returns the player's health.
	int health() const;

	// Sets the position of the player within the world
	void setPosition(int x, int y);

	// Subtracts health from the player's health.
	void damage(int health);

	// Adds health to the player's health.
	void heal(int health);
	
	// Sets health so arbitrary level
	void setHealth(int health);
	

};

#endif // PLAYER_HPP