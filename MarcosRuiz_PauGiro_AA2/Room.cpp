#include "Room.h"

void Room::CreateRoom(const int& width, const int& height, int numberOfRoom)
{
	
	m_width = width;
	m_height = height;

	link.x = m_width / 2;
	if (link.m_direction == Direction::DOWN)
	{
		link.y = 1;
	}
	else
	{
		link.y = m_height - 2;
	}

	room = new char* [m_height];

	for (int i = 0; i < m_height; i++)
	{
		room[i] = new char[m_width];
	}
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (link.x == j && link.y == i)
			{

				room[i][j] = (char)link.m_direction;
			}
			else if (i == 0 && j == m_width / 2)
			{
				
				if (numberOfRoom != 3)
					room[i][j] = 'P';
				else
					room[i][j] = 'X';
			}
			else if (i == (m_height - 1) && j == m_width / 2)
			{
				if (numberOfRoom != 1)
				
					room[i][j] = 'P';
				else
					room[i][j] = 'X';
			}
			else if (i == 0 || i == (m_height - 1) || j == 0 || j == (m_width - 1))
			{	
				room[i][j] = 'X';
			}
			else
			{
				room[i][j] = ' ';
			}
		}
	}
}

void Room::PrintRoom()
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (link.x == j && link.y == i)
			{
				std::cout <<player<< room[i][j] << ' ';
			}
			else if (room[i][j] == 'P')
			{
				std::cout << door << room[i][j] << ' ';
			}
			else
			{
				std::cout <<wall<< room[i][j] << ' ';
			}
			
		}
		std::cout << std::endl;
	}
}

char Room::CheckMovement(const InputKey& key)
{
	switch (key)
	{
	case InputKey::K_UP:
		return ReturnSquare(link.y - 1, link.x);
		break;
	case InputKey::K_DOWN:
		return ReturnSquare(link.y + 1, link.x);
		break;
	case InputKey::K_LEFT:
		return ReturnSquare(link.y, link.x - 1);
		break;
	case InputKey::K_RIGHT:
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
	return room[height][width];
}

void Room::MoveLink(const InputKey& key)
{
	if (CheckMovement(key) == ' ')
	{
		room[link.y][link.x] = ' ';
		switch (key)
		{
		case InputKey::K_UP:
			link.MoveUp();
			break;
		case InputKey::K_DOWN:
			link.MoveDown();
			break;
		case InputKey::K_LEFT:
			link.MoveLeft();
			break;
		case InputKey::K_RIGHT:
			link.MoveRight();
			break;
		case InputKey::K_SPACE:
			link.MoveRight();
			break;
		}
	}
	else
	{
		switch (key)
		{
		case InputKey::K_UP:
			link.m_direction = Direction::UP;
			break;
		case InputKey::K_DOWN:
			link.m_direction = Direction::DOWN;
			break;
		case InputKey::K_LEFT:
			link.m_direction = Direction::LEFT;
			break;
		case InputKey::K_RIGHT:
			link.m_direction = Direction::RIGHT;
			break;
		}
	}
	room[link.y][link.x] = (char)link.m_direction;
}

Player Room::GetLink()
{
	return link;
}


