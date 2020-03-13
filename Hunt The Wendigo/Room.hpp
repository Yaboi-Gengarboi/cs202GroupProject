// Room.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/12/2020
// Last updated on 3/12/2020

#include <memory> // std::shared_ptr

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
	std::shared_ptr<Room> _roomUp = nullptr;
	std::shared_ptr<Room> _roomLeft = nullptr;
	std::shared_ptr<Room> _roomRight = nullptr;
	std::shared_ptr<Room> _roomDown = nullptr;

	public:

	Room();
	
	Room(short int id);

	~Room();

	short int ID();

	std::shared_ptr<Room> roomUp();
	std::shared_ptr<Room> roomLeft();
	std::shared_ptr<Room> roomRight();
	std::shared_ptr<Room> roomDown();

	void setRoomUp(const Room& room);
	void setRoomLeft(const Room& room);
	void setRoomRight(const Room& room);
	void setRoomDown(const Room& room);
};

bool areRoomsAdjacent(const Room& room1, const Room& room2);

#endif // ROOM_HPP