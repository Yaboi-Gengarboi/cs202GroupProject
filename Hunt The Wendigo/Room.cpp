// Room.cpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/12/2020
// Last updated on 3/24/2020

#include "Room.hpp"
// <memory>
// <array>

using std::shared_ptr;
using std::make_shared;

Room::Room() {}

Room::Room(short int id)
{
	_id = id;
}

Room::~Room() {}

short int Room::ID() const
{
	return _id;
}

void Room::setID(short int id)
{
	_id = id;
}

shared_ptr<Room> Room::getAdjacentRoom(short int index) const
{
	if (index >= 0 && index < 4)
		return _adjRooms[index];

	return nullptr;
}

void Room::setAdjacentRoom(const Room& room, short int index)
{
	if (index >= 0 && index < 4)
		_adjRooms[index] = make_shared<Room>(room);
}

bool operator == (const Room& room1, const Room& room2)
{
	return (room1.ID() == room2.ID());
}

bool areRoomsAdjacent(const Room& room1, const Room& room2)
{
	for (short int i = 0; i < 4; ++i)
	{
		if (*(room1.getAdjacentRoom(i)) == room2)
			return true;
	}

	return false;
}