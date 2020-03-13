// Room.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/12/2020
// Last updated on 3/12/2020

#include <memory> // std::shared_ptr
#include <vector> // std::vector

#ifndef ROOM_HPP
#define ROOM_HPP

/*

*/
class Room
{
	short int _id = -1;

	/* These std::shared_ptrs will point to adjacent rooms.
	   They will be initialized as nullptr so we will need
	   to check for that in functions.
	*/
	std::vector<std::shared_ptr<Room>> _adjRooms = { nullptr, nullptr, nullptr, nullptr };

	public:

	Room();
	
	Room(short int id);

	~Room();

	short int ID() const;

	void setID(short int id);

	std::shared_ptr<Room> getRoom(short int index) const;

	void setRoom(const Room& room, short int index);
};

bool operator == (const Room& room1, const Room& room2);

bool areRoomsAdjacent(const Room& room1, const Room& room2);

#endif // ROOM_HPP