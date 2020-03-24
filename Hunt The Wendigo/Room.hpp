// Room.hpp
// Justyn Durnford
// Izac Lorimer
// Created on 3/12/2020
// Last updated on 3/24/2020

#include <memory> // std::shared_ptr
#include <array> // std::array

#ifndef ROOM_HPP
#define ROOM_HPP

// The Room class will function as nodes for the world grid
// which the player, Wendigo and other objects will inhabit.
// Each room has an ID for comparison reasons and shared_ptrs
// to adjacent rooms. 
class Room
{
	// Identification method. -1 indicates an uninitialized room.
	short int _id = -1;

	// These std::shared_ptrs will point to adjacent rooms.
	// They will be initialized as nullptr so we will need
	// to check for that in functions.
	std::array<std::shared_ptr<Room>, 4> _adjRooms = { nullptr, nullptr, nullptr, nullptr };

	public:

	// Default constructor. Don't use.
	Room();
	
	// Standard constructor.
	Room(short int id);

	// Destructor.
	~Room();

	// Returns _id.
	short int ID() const;

	// Sets the value of _id to id.
	void setID(short int id);

	// Returns a shared_ptr to the adjacent room specified by index.
	std::shared_ptr<Room> getAdjacentRoom(short int index) const;

	// Sets the value of the shared_ptr to the adjacent room specified
	// by index to point to room.
	void setAdjacentRoom(const Room& room, short int index);
};

// Returns true if the two rooms have the same ID.
bool operator == (const Room& room1, const Room& room2);

// Returns true if the two rooms are determined to be adjacent.
bool areRoomsAdjacent(const Room& room1, const Room& room2);

#endif // ROOM_HPP