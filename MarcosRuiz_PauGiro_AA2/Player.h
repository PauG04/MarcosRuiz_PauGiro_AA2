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
private:
	int x, y, m_rupias, m_hearts;
	Direction m_direction;

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

public:
	int GetHearts() const;
	void SetDirection(const Direction& direction);
	void SetHearts(const int& hearts);

	friend class Room;
};

