#pragma once
#include "Input.h"
#include <iostream>
#include <windows.h>


enum class Direction
{
	UP = '^',
	DOWN = 'v',
	LEFT = '<',
	RIGHT = '>',
};

class Player
{
public:
	int x, y, rupias, hearts;
	Direction m_direction;

public:
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	friend class Room;
};

