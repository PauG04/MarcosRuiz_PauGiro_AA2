#pragma once
#include "Player.h"

class Room
{
private:
	char** room;
	int m_width;
	int m_height;
	const std::string player = "\x1b[32m"; //green
	const std::string wall = "\x1b[37m"; //grey
	const std::string door = "\x1b[31m"; //red

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

