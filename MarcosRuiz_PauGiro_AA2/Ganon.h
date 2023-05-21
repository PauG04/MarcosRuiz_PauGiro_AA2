#pragma once

class Ganon
{
	int x, y, health, direction;

public:
	void MoveUpG();
	void MoveDownG();
	void MoveRighG();
	void MoveLeftG();

	friend class Room;
};
