#pragma once
#include <iostream>
#include <windows.h>


enum class Direction
{
	UP = '^',
	DOWN = 'v',
	LEFT = '<',
	RIGHT = '>',
	BUG,
	ESCAPE
};

class Player
{
public:
	int x, y;
	Direction m_direction;

public:
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	friend class Room;
};

