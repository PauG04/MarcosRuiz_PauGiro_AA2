#include "Room.h"

void Room::CreateRoom(const int& width, const int& height, int numberOfRoom)
{
	
	m_width = width;
	m_height = height;
	
	pot->potSize = 1;
	

	link.x = m_width / 2;
	if (link.m_direction == Direction::DOWN)
	{
		link.y = 1;
	}
	else
	{
		link.y = m_height - 2;
	}
	for (int k = 0; k < pot->potSize; k++)
	{
		pot[k].x = rand() % ((m_width - 2) - 1 + 1) + 1;
		pot[k].y = rand() % ((m_height - 2) - 1 + 1) + 1;	
		pot[k].value = rand() % 3;
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
			else if (pot[pots].x == j && pot[pots].y == i)
			{
				room[i][j] = 'O';	
				pots++;			
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
			else if (room[i][j] == 'O')
			{
				std::cout << potColor << room[i][j] << ' ';
			}
			else if (room[i][j] == '$')
			{
				std::cout << rupia1 << room[i][j] << ' ';
			}
			else if (room[i][j] == '#')
			{
				std::cout << rupia2 << room[i][j] << ' ';
			}
			else if (room[i][j] == '&')
			{
				std::cout << rupia3 << room[i][j] << ' ';
			}
			else
			{
				std::cout <<wall<< room[i][j] << ' ';
			}
			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Hearts: " << link.hearts << "     " << "Rupias: " << link.rupias;

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
	if (CheckMovement(key) == ' ' || CheckMovement(key) == '$' || CheckMovement(key) == '#' || CheckMovement(key) == '&')
	{
		room[link.y][link.x] = ' ';
		if (CheckMovement(key) == '$')
			link.rupias += 1;
		else if (CheckMovement(key) == '#')
			link.rupias += 5;
		else if (CheckMovement(key) == '&')
			link.rupias += 20;
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
	 if (key == InputKey::K_SPACE)
	{
		switch (link.m_direction)
		{
		case Direction::UP:
			if (ReturnSquare(link.y -1, link.x) == 'O')
				if (pot->value == 1)
				{
					room[link.y - 1][link.x] = '$';
				}
				else if (pot->value == 2)
				{
					room[link.y - 1][link.x] = '#';
				}
				else
				{
					room[link.y - 1][link.x] = '&';
				}			
			break;
		case Direction::DOWN:
			if (ReturnSquare(link.y +1, link.x)== 'O')
				if (pot->value == 1)
				{
					room[link.y + 1][link.x] = '$';
				}
				else if (pot->value == 2)
				{
					room[link.y + 1][link.x] = '#';
				}
				else
				{
					room[link.y + 1][link.x] = '$';
				}			
			break;
		case Direction::LEFT:
			if (ReturnSquare(link.y, link.x-1)== 'O')
				if (pot->value == 1)
				{
					room[link.y][link.x - 1] = '$';
				}
				else if (pot->value == 2)
				{
					room[link.y][link.x - 1] = '#';
				}
				else
				{
					room[link.y][link.x - 1] = '&';
				}
			break;
		case Direction::RIGHT:
			if (ReturnSquare(link.y, link.x+1) == 'O')
				if (pot->value == 1)
				{
					room[link.y][link.x + 1] = '$';
				}
				else if (pot->value == 2)
				{
					room[link.y][link.x + 1] = '#';
				}
				else
				{
					room[link.y][link.x + 1] = '&';
				}
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
		default:
			return;
		}
	}
	room[link.y][link.x] = (char)link.m_direction;
}

Player Room::GetLink()
{
	return link;
}


