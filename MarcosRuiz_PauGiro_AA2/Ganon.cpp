#include "Ganon.h"

void Ganon::MoveUpG()
{
	y--;
}

void Ganon::MoveDownG()
{
	y++;
}

void Ganon::MoveRightG()
{
	x++;
}

void Ganon::MoveLeftG()
{
	x--;
}

void Ganon::SetHealth(const int& health)
{
	m_health = health;
}