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
	void CreateRoom(const int& numRows, const int& numCols);

	void PrintRoom();

	bool EnterDoor(Direction key);

	char CheckMovement(Direction key);

	void DestroyRoom();

	void MoveLink(Direction key);

	char ReturnSquare(int height, int width);

	Player GetLink()
	{
		return link;
	}

	friend class Game;
};

