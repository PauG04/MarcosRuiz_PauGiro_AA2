#pragma once

class Ganon
{
private:
	int x, y, health, direction;

	void MoveUpG();
	void MoveDownG();
	void MoveRightG();
	void MoveLeftG();

public:
	
	friend class Room;
};
