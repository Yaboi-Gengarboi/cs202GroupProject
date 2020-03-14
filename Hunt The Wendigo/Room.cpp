// Room.cpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/12/2020
// Last updated on 3/13/2020

#include "Room.hpp"
// <memory>
// <vector>

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

shared_ptr<Room> Room::getRoom(short int index) const
{
	return _adjRooms[index];
}

void Room::setRoom(const Room& room, short int index)
{
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
		if (*(room1.getRoom(i)) == room2)
			return true;
	}

	return false;
}