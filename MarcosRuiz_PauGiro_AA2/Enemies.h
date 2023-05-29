#pragma once

class Enemies
{
private:
	int x, y, enemeisSize, direction, startDirection;
	bool isAlive;

	void MoveUpE();
	void MoveDownE();
	void MoveRighE();
	void MoveLeftE();

public:

	friend class Room;

};
