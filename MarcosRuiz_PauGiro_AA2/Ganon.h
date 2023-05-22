#pragma once

class Ganon
{
	int x, y, health, direction;

public:
	void MoveUpG();
	void MoveDownG();
	void MoveRightG();
	void MoveLeftG();

	friend class Room;
};
