#pragma once

class Ganon
{
private:
	int x, y, m_health, m_direction;

	void MoveUpG();
	void MoveDownG();
	void MoveRightG();
	void MoveLeftG();

public:
	
	void SetHealth(const int& health);
	friend class Room;
};
