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

int Player::GetHearts() const
{
	return m_hearts;
}

void Player::SetDirection(const Direction& direction)
{
	m_direction = direction;
}

void Player::SetHearts(const int& hearts)
{
	m_hearts = hearts;
}