#pragma once

class Enemies
{
	int x, y, enemeisSize, direction, startDirection;

public:
	void MoveUpE();
	void MoveDownE();
	void MoveRighE();
	void MoveLeftE();

	friend class Room;

};
