#include "Player.h"

void Player::MoveUp()
{
	y--;
	m_direction = Direction::UP;
}
void Player::MoveDown()
{
	y++;
	m_direction = Direction::DOWN;
}
void Player::MoveRight()
{
	x++;
	m_direction = Direction::RIGHT;
}
void Player::MoveLeft()
{
	x--;
	m_direction = Direction::LEFT;
}
