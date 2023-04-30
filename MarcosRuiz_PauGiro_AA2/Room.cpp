#include "Room.h"


void Room::CreateRoom(const int& width, const int& height)
{
	m_width = width;
	m_height = height;

	link.x = m_height / 2;
	link.y = m_width - 2;

	
	//if !pillasPuertaDeArriba
	link.m_direction = Direction::UP;
	//else
	//link.direction = Direction::DOWN;

	room = new char* [m_height];

	for (int i = 0; i < m_height; i++)
	{
		room[i] = new char[m_width];
	}

	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			if (link.x == j && link.y == i)
			{
				room[j][i] = (char)link.m_direction;
			}
				
			else if ((i == 0 || i == (m_width - 1)) && j == m_height / 2)
			{
				room[j][i] = 'P';
			
			}
				
			else if (i == 0 || i == (m_width - 1) || j == 0 || j == (m_height - 1))
			{
				room[j][i] = 'X';
			}
			else
			{
				room[j][i] = ' ';
				
			}
		}
	}
}

void Room::PrintRoom()
{
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			std::cout << room[j][i] << ' ';
		}
		std::cout << std::endl;
	}
}

char Room::CheckMovement(Direction key)
{
	switch (key)
	{
	case Direction::UP:
		return ReturnSquare(link.y - 1, link.x);
		break;
	case Direction::DOWN:
		return ReturnSquare(link.y + 1, link.x);
		break;
	case Direction::LEFT:
		return ReturnSquare(link.y, link.x - 1);
		break;
	case Direction::RIGHT:
		return ReturnSquare(link.y, link.x + 1);
		break;
	default:
		return '?';
		break;
	}

}

void Room::DestroyRoom()
{
	for (int i = 0; i < m_width; i++)
		delete[] room[i];
	delete[] room;
	room = nullptr;
}

char Room::ReturnSquare(int height, int width)
{
	return room[width][height];
}

void Room::MoveLink(Direction key)
{
	if (CheckMovement(key) == ' ')
	{
		room[link.x][link.y] = ' ';
		switch (key)
		{
		case Direction::UP:
			link.y -= 1;
			link.m_direction = Direction::UP;
			break;
		case Direction::DOWN:
			link.y += 1;
			link.m_direction = Direction::DOWN;
			break;
		case Direction::LEFT:
			link.x -= 1;
			link.m_direction = Direction::LEFT;
			break;
		case Direction::RIGHT:
			link.x += 1;
			link.m_direction = Direction::RIGHT;
			break;
		}
		room[link.x][link.y] = (char)link.m_direction;
	}
}

bool Room::EnterDoor(Direction key)
{
	if (CheckMovement(key) == 'P')
		return true;

	return false;

}

Player Room::GetLink()
{
	return link;
}


