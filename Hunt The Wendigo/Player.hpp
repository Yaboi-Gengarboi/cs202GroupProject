// Player.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/13/2020
// Last updated on 3/13/2020

#include "Room.hpp"
// <memory>
// <vector>

#include <string> // std::string

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	//
	std::string _name = "";

	//
	std::shared_ptr<Room> _currentRoom = nullptr;

	//
	int _health = -1;

	public:

	//
	Player();

	//
	Player(const std::string& name, const Room& currentRoom, int health);

	//
	~Player();

	//
	std::string name() const;

	//
	std::shared_ptr<Room> currentRoom() const;

	//
	int health() const;

	//
	void setName(const std::string& name);

	//
	void setCurrentRoom(const Room& room);

	//
	void damage(int health);

	//
	void heal(int health);

	

};

#endif // PLAYER_HPP