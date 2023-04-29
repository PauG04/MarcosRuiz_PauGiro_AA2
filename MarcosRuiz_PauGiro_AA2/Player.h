#pragma once
#include <iostream>
#include <windows.h>

enum class Direction
{
	UP = '^',
	DOWN = 'v',
	LEFT = '<',
	RIGHT = '>',
	BUG = '?'
};

class Player
{
public:
	int x, y;
	Direction m_direction;

public:

	friend class Room;
};

