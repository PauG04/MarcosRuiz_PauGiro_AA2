#pragma once
#include "Player.h"

class Room
{
private:
	char** room;
	int m_width;
	int m_height;

	Player link;
	

public:
	void CreateRoom(const int& width, const int& height, int numberOfRoom);

	void PrintRoom();

	char CheckMovement(Direction key);

	void DestroyRoom();

	void MoveLink(Direction key);

	char ReturnSquare(int height, int width);

	Player GetLink();

	friend class Game;
};

