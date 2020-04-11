// Player.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 4/16/2020
// Last updated on 4/10/2020


#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Room.hpp"

class Game {
private:
	Player* player = nullptr;
public:
	Game(unsigned seed);
	void tick();
};

struct Item {
	int id;
	std::string name;
	std::string description;
	int quantity;
};

#endif
