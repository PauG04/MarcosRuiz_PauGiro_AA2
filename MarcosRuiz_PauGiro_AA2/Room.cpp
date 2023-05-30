#include "Room.h"

int Room::RandomNumber(int max, int min)
{
	return rand() % (max - min + 1) + min;
}

void Room::SetPotPosition()
{
	for (int k = 0; k < m_numberOfPots; k++)
	{
		pot[k].x = RandomNumber(m_width - 2, 1);
		pot[k].y = RandomNumber(m_height - 2, 1);
		pot[k].value = RandomNumber(3, 1);
		while ((pot[k].x == link.x && pot[k].y == link.y)|| (pot[k].x == ganon.x && pot[k].y == ganon.y))
		{
			pot[k].x = RandomNumber(m_width - 2, 1);
			pot[k].y = RandomNumber(m_height - 2, 1);
		}
		for (int i = 0; i < k; i++)
		{
			while (pot[k].x == pot[i].x && pot[k].y == pot[i].y)
			{
				pot[k].x = RandomNumber(m_width - 2, 1);
				pot[k].y = RandomNumber(m_height - 2, 1);
			}
		}
	}

}

void Room::SetEnemiesPosition()
{
	for (int k = 0; k < m_numberOfEnemies; k++)
	{
		enemies[k].x = RandomNumber(m_width - 2, 1);
		enemies[k].y = RandomNumber(m_height - 2, 1);
		while ((enemies[k].x == link.x && enemies[k].y == link.y)|| (enemies[k].x == ganon.x && enemies[k].y == ganon.y))
		{
			enemies[k].x = RandomNumber(m_width - 2, 1);
			enemies[k].y = RandomNumber(m_height - 2, 1);
		}
		for (int i = 0; i < k; i++)
		{
			while (enemies[k].x == enemies[i].x && enemies[k].y == enemies[i].y)
			{
				enemies[k].x = RandomNumber(m_width - 2, 1);
				enemies[k].y = RandomNumber(m_height - 2, 1);
			}
		}
		for (int i = 0; i < m_numberOfPots; i++)
		{
			while (enemies[k].x == pot[i].x && enemies[k].y == pot[i].y)
			{
				enemies[k].x = RandomNumber(m_width - 2, 1);
				enemies[k].y = RandomNumber(m_height - 2, 1);
			}
		}
	}
}

void Room::CreateGanon(const int& width, const int& height)
{
	ganon.x = RandomNumber(width - 2, 1);
	ganon.y = RandomNumber(height - 2, 1);
	ganon.m_direction = RandomNumber(4, 1);
	while (ganon.x == link.x && ganon.y == link.y)
	{
		ganon.x = RandomNumber(width - 2, 1);
		ganon.y = RandomNumber(height - 2, 1);
	}
}

void Room::CreatePlayer()
{
	link.m_rupias = 0;
}

void Room::CreateEnemies()
{
	enemies = new Enemies[m_numberOfEnemies];
	for (int i = 0; i < m_numberOfEnemies; i++)
	{
		enemies[i].direction = RandomNumber(2, 1);
		enemies[i].startDirection = RandomNumber(2, 1);
		enemies[i].isAlive = true;
	}
}

void Room::CreateRoom(const int& width, const int& height, const int& numberOfRoom, const int& numberOfPots, const int& numberOfEnemies)
{
	
	m_width = width;
	m_height = height;

	m_numberOfPots = numberOfPots;
	m_numberOfEnemies = numberOfEnemies;
	m_numberOfRoom = numberOfRoom;
	pot = new Pot[m_numberOfPots];
	CreateEnemies();
	link.x = m_width / 2;
	if (link.m_direction == Direction::DOWN)
	{
		link.y = 1;
	}
	else
	{
		link.y = m_height - 2;
	}
	SetPotPosition();
	SetEnemiesPosition();
	
	room = new char* [m_height];

	for (int i = 0; i < m_height; i++)
	{
		room[i] = new char[m_width];
	}
	
	SetChars(m_numberOfRoom);
}

void Room::SetChars(int numberOfRoom)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			for (int k = 0; k < m_numberOfPots; k++)
			{
				if (pot[k].x == j && pot[k].y == i)
				{
					room[i][j] = 'O';
				}
			}
			for (int k = 0; k < m_numberOfEnemies; k++)
			{
				if (enemies[k].x == j && enemies[k].y == i)
				{
					room[i][j] = 'S';
				}
			}
			if (link.x == j && link.y == i)
			{

				room[i][j] = (char)link.m_direction;
			}
			else if (ganon.x == j && ganon.y == i && numberOfRoom == 3)
			{
				room[i][j] = 'G';
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
				if (room[i][j] != 'O' && room[i][j] != 'S')
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
			else if (room[i][j] == 'S' || room[i][j] == 'G')
			{
				std::cout << enemy << room[i][j] << ' ';
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
	std::cout << "Hearts: " << link.m_hearts << "     " << "Rupias: " << link.m_rupias;
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

void Room::DestroyPot()
{
	delete[] pot;
	pot = nullptr;
}

void Room::DestroyEnemy()
{
	delete[] enemies;
	enemies = nullptr;
}

char Room::ReturnSquare(int height, int width)
{
	return room[height][width];
}

void Room::MoveEnemies()
{
	for (int i = 0; i < m_numberOfEnemies; i++)
	{
		if (enemies[i].isAlive)
		{
			room[enemies[i].y][enemies[i].x] = ' ';
			if (enemies[i].direction == 1 && enemies[i].startDirection == 1)
			{
				if (room[enemies[i].y + 1][enemies[i].x] == ' ' || (enemies[i].y + 1 == link.y && enemies[i].x == link.x))
				{
					enemies[i].MoveDownE();
				}
				else
				{
					enemies[i].startDirection = 2;
				}
			}
			else if (enemies[i].direction == 1 && enemies[i].startDirection == 2)
			{
				if (room[enemies[i].y - 1][enemies[i].x] == ' ' || (enemies[i].y - 1 == link.y && enemies[i].x == link.x))
				{
					enemies[i].MoveUpE();
				}
				else
				{
					enemies[i].startDirection = 1;
				}
			}
			else if (enemies[i].direction == 2 && enemies[i].startDirection == 1)
			{
				if (room[enemies[i].y][enemies[i].x + 1] == ' ' || (enemies[i].x + 1 == link.x && enemies[i].y == link.y))
				{

					enemies[i].MoveRighE();
				}
				else
				{
					enemies[i].startDirection = 2;
				}
			}
			else if (enemies[i].direction == 2 && enemies[i].startDirection == 2)
			{
				if (room[enemies[i].y][enemies[i].x - 1] == ' ' || (enemies[i].x - 1 == link.x && enemies[i].y == link.y))
				{
					enemies[i].MoveLeftE();
				}
				else
				{
					enemies[i].startDirection = 1;
				}		
			}
			room[enemies[i].y][enemies[i].x] = 'S';
		}	
	}
}

void Room::MoveGanon()
{
	if (m_numberOfRoom == 3)
	{
		room[ganon.y][ganon.x] = ' ';
		switch (ganon.m_direction)
		{
		case 1:
			if (room[ganon.y + 1][ganon.x] == ' ' || (ganon.y + 1 == link.y && ganon.x == link.x))
			{
				ganon.MoveDownG();
			}
			else
			{
				ganon.m_direction = RandomNumber(4, 1);
			}
			break;
		case 2:
			if (room[ganon.y - 1][ganon.x] == ' ' || (ganon.y - 1 == link.y && ganon.x == link.x))
			{
				ganon.MoveUpG();
			}
			else
			{
				ganon.m_direction = RandomNumber(4, 1);
			}
			break;
		case 3:
			if (room[ganon.y][ganon.x + 1] == ' ' || (ganon.y == link.y && ganon.x + 1 == link.x))
			{
				ganon.MoveRightG();
			}
			else
			{
				ganon.m_direction = RandomNumber(4, 1);
			}
			break;
		case 4:
			if (room[ganon.y][ganon.x - 1] == ' ' || (ganon.y == link.y && ganon.x - 1 == link.x))
			{
				ganon.MoveLeftG();
			}
			else
			{
				ganon.m_direction = RandomNumber(4, 1);
			}
			break;
		}
		ganon.m_direction = RandomNumber(4, 1);
		room[ganon.y][ganon.x] = 'G';
	}
}

void Room::MoveLink(const InputKey& key)
{
	if (key == InputKey::K_SPACE)
	{
		switch (link.m_direction)
		{
		case Direction::UP:
			if (ReturnSquare(link.y - 1, link.x) == 'O')
			{
				for (int k = 0; k < m_numberOfPots; k++)
				{
					if (ReturnSquare(pot[k].y + 1, pot[k].x) == '^')
					{
						if (pot[k].value == 1)
							room[link.y - 1][link.x] = '$';
						else if (pot[k].value == 2)
							room[link.y - 1][link.x] = '#';
						else if (pot[k].value == 3)
							room[link.y - 1][link.x] = '&';
					}
				}
			}
			if (ReturnSquare(link.y - 1, link.x) == 'S')
			{
				for (int i = 0; i < m_numberOfEnemies; i++)
				{
					if (ReturnSquare(enemies[i].y + 1, enemies[i].x) == '^')
					{
						room[link.y-1][link.x] = ' ';
						enemies[i].isAlive = false;
					}

				}
			}
			if (ReturnSquare(link.y - 1, link.x) == 'G')
			{
				ganon.m_health--;
			}
			break;
		case Direction::DOWN:
			if (ReturnSquare(link.y + 1, link.x) == 'O')
			{
				for (int k = 0; k < m_numberOfPots; k++)
				{
					if (ReturnSquare(pot[k].y - 1, pot[k].x) == 'v')
					{
						if (pot[k].value == 1)
							room[link.y + 1][link.x] = '$';
						else if (pot[k].value == 2)
							room[link.y + 1][link.x] = '#';
						else if (pot[k].value == 3)
							room[link.y + 1][link.x] = '&';
					}
				}
			}
			if (ReturnSquare(link.y + 1, link.x) == 'S')
			{
				for (int i = 0; i < m_numberOfEnemies; i++)
				{
					if (ReturnSquare(enemies[i].y-1, enemies[i].x) == 'v')
					{
						room[link.y + 1][link.x] = ' ';
						enemies[i].isAlive = false;
					}

				}
			}
			if (ReturnSquare(link.y + 1, link.x) == 'G')
			{
				ganon.m_health--;
			}
			break;
		case Direction::LEFT:
			if (ReturnSquare(link.y, link.x - 1) == 'O')
			{
				for (int k = 0; k < m_numberOfPots; k++)
				{
					if (ReturnSquare(pot[k].y, pot[k].x + 1) == '<')
					{
						if (pot[k].value == 1)
							room[link.y][link.x - 1] = '$';
						else if (pot[k].value == 2)
							room[link.y][link.x - 1] = '#';
						else if (pot[k].value == 3)
							room[link.y][link.x - 1] = '&';
					}
				}
			}
			if (ReturnSquare(link.y, link.x - 1) == 'S')
			{
				for (int i = 0; i < m_numberOfEnemies; i++)
				{
					if (ReturnSquare(enemies[i].y, enemies[i].x + 1) == '<')
					{
						room[link.y][link.x - 1] = ' ';
						enemies[i].isAlive = false;
					}

				}
			}
			if (ReturnSquare(link.y, link.x - 1) == 'G')
			{
				ganon.m_health--;
			}
			break;
		case Direction::RIGHT:
			if (ReturnSquare(link.y, link.x + 1) == 'O')
			{
				for (int k = 0; k < m_numberOfPots; k++)
				{
					if (ReturnSquare(pot[k].y, pot[k].x - 1) == '>')
					{
						if (pot[k].value == 1)
							room[link.y][link.x + 1] = '$';
						else if (pot[k].value == 2)
							room[link.y][link.x + 1] = '#';
						else if (pot[k].value == 3)
							room[link.y][link.x + 1] = '&';
					}
				}
			}
			if (ReturnSquare(link.y, link.x + 1) == 'S')
			{
				for (int i = 0; i < m_numberOfEnemies; i++)
				{
					if (ReturnSquare(enemies[i].y, enemies[i].x - 1) == '>')
					{
						room[link.y][link.x + 1] = ' ';
						enemies[i].isAlive = false;
					}
						
				}
				
			}
			if (ReturnSquare(link.y, link.x + 1) == 'G')
			{
				ganon.m_health--;
			}
			break;
		}
	}
	if(CheckMovement(key) != 'X' && CheckMovement(key) != 'O' && CheckMovement(key) != 'P')
	{
		room[link.y][link.x] = ' ';
		if (CheckMovement(key) == '$')
			link.m_rupias += 1;
		else if (CheckMovement(key) == '#')
			link.m_rupias += 5;
		else if (CheckMovement(key) == '&')
			link.m_rupias += 20;
		else if (CheckMovement(key) == 'S')
			link.m_hearts--;
		else if (CheckMovement(key) == 'G')
			link.m_hearts -= 2;
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

void Room::GetHitted()
{
	for (int i = 0; i < m_numberOfEnemies; i++)
	{
		if (enemies[i].y == link.y && enemies[i].x == link.x && enemies[i].isAlive)
		{
			link.m_hearts--;
		}
	}
	if (ganon.x == link.x && ganon.y == link.y)
	{
		link.m_hearts -= 2;
	}
}

bool Room::GanonAlive()
{
	if (ganon.m_health <= 0)
	{
		room[ganon.y][ganon.x] = ' ';
		return false;
	}
	return true;
}

Player Room::GetLink()
{
	return link;
}


