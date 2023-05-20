#include "Room.h"

int Room::RandomNumber(int max, int min)
{
	return rand() % ((max)-1 + 1) + 1;
}

void Room::SetPotPosition(const int& width, const int& height, const int& size, Pot pot[], Player link)
{
	for (int k = 0; k < size; k++)
	{
		pot[k].x = RandomNumber(width - 2, 1);
		pot[k].y = RandomNumber(height - 2, 1);
		pot[k].value = RandomNumber(3, 1);
		while ((pot[k].x == link.x && pot[k].y == link.y))
		{
			pot[k].x = RandomNumber(width - 2, 1);
			pot[k].y = RandomNumber(height - 2, 1);
		}
		for (int i = 0; i < k; i++)
		{
			while (pot[k].x == pot[i].x && pot[k].y == pot[i].y)
			{
				pot[k].x = RandomNumber(width - 2, 1);
				pot[k].y = RandomNumber(height - 2, 1);
			}
		}
	}

}

void Room::SetEnemiesPosition(const int& width, const int& height, const int& size, Pot pot[], Player link, Enemies enemy[], const int& potSize)
{
	for (int k = 0; k < size; k++)
	{
		enemy[k].x = RandomNumber(width - 2, 1);
		enemy[k].y = RandomNumber(height - 2, 1);
		while ((enemy[k].x == link.x && enemy[k].y == link.y))
		{
			enemy[k].x = RandomNumber(width - 2, 1);
			enemy[k].y = RandomNumber(height - 2, 1);
		}
		for (int i = 0; i < k; i++)
		{
			while (enemy[k].x == enemy[i].x && enemy[k].y == enemy[i].y)
			{
				enemy[k].x = RandomNumber(width - 2, 1);
				enemy[k].y = RandomNumber(height - 2, 1);
			}
		}
		for (int i = 0; i < potSize; i++)
		{
			while (enemy[k].x == pot[i].x && enemy[k].y == pot[i].y)
			{
				enemy[k].x = RandomNumber(width - 2, 1);
				enemy[k].y = RandomNumber(height - 2, 1);
			}
		}
	}
}

void Room::CreatePlayer(const int& hearts)
{
	link.rupias = 0;
	link.hearts = hearts;
}

void Room::CreateEnemies()
{
	enemies = new Enemies[m_enemies];
	for (int i = 0; i < m_enemies; i++)
	{
		enemies[i].direction = RandomNumber(2, 1);
		enemies[i].startDirection = RandomNumber(2, 1);
	}
}

void Room::CreateRoom(const int& width, const int& height, int numberOfRoom)
{
	
	m_width = width;
	m_height = height;
	m_potSize = 3;	
	m_enemies = 2;
	pot = new Pot[m_potSize];
	CreateEnemies();
	int pots = 0;

	link.x = m_width / 2;
	if (link.m_direction == Direction::DOWN)
	{
		link.y = 1;
	}
	else
	{
		link.y = m_height - 2;
	}
	SetPotPosition(m_width, m_height, m_potSize, pot, link);
	SetEnemiesPosition(m_width, m_height, m_enemies, pot, link, enemies, m_potSize);
	room = new char* [m_height];

	for (int i = 0; i < m_height; i++)
	{
		room[i] = new char[m_width];
	}
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			for (int k = 0; k < m_potSize; k++)
			{
				if (pot[k].x == j && pot[k].y == i)
				{
					room[i][j] = 'O';

				}
			}
			for (int k = 0; k < m_enemies; k++)
			{
				if (enemies[k].x == j && enemies[k].y == i)
				{
					room[i][j] = 'J';

				}
			}
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
				if(room[i][j] != 'O' && room[i][j] != 'J')
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
			else if (room[i][j] == 'J')
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
char Room::CheckMovementE(const int startDirection, const int direction, const int i)
{
	
		if (direction == 1)
		{
			switch (startDirection)
			{
			case 1:
				return ReturnSquare(enemies[i].y - 1, enemies[i].x);
				break;
			case 2:
				return ReturnSquare(enemies[i].y + 1, enemies[i].x);
				break;
			}
		}
		else
		{
			switch (startDirection)
			{
			case 1:
				return ReturnSquare(enemies[i].y, enemies[i].x + 1);
				break;
			case 2:
				return ReturnSquare(enemies[i].y, enemies[i].x - 1);
				break;
			}
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

char Room::ReturnSquare(int height, int width)
{
	return room[height][width];
}

void Room::MoveEnemies()
{
	for (int i = 0; i < m_enemies; i++)
	{
 		room[enemies[i].y][enemies[i].x] = ' ';
		if (enemies[i].direction ==  1 && enemies[i].startDirection == 1)
		{
			if (room[enemies[i].y+1][enemies[i].x] == ' '|| enemies[i].y + 1 != link.y)
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
			if (room[enemies[i].y - 1][enemies[i].x] == ' ' || enemies[i].y - 1 != link.y)
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
			if (room[enemies[i].y][enemies[i].x+1]== ' ' || enemies[i].x + 1 != link.x)
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
			if (room[enemies[i].y - 1][enemies[i].x-1] == ' ' || enemies[i].x - 1 != link.x)
			{
				enemies[i].MoveLeftE();
			}
			else
			{
				enemies[i].startDirection = 1;
			}
		}
		room[enemies[i].y][enemies[i].x] = 'J';
	}
}


void Room::MoveLink(const InputKey& key)
{
	if (CheckMovement(key) == ' ' || CheckMovement(key) == '$' || CheckMovement(key) == '#' || CheckMovement(key) == '&' || CheckMovement(key) == 'J')
	{
		room[link.y][link.x] = ' ';
		if (CheckMovement(key) == '$')
			link.rupias += 1;
		else if (CheckMovement(key) == '#')
			link.rupias += 5;
		else if (CheckMovement(key) == '&')
			link.rupias += 20;
		else if (CheckMovement(key) == 'J')
			link.hearts--;
			
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
			if (ReturnSquare(link.y - 1, link.x) == 'O')
			{
				for (int k = 0; k < m_potSize; k++)
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
			if (ReturnSquare(link.y - 1, link.x) == 'J')
			{
				room[link.y - 1][link.x] = ' ';
			}
			break;
		case Direction::DOWN:
			if (ReturnSquare(link.y + 1, link.x) == 'O')
			{
				for (int k = 0; k < m_potSize; k++)
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
			if (ReturnSquare(link.y + 1, link.x) == 'J')
			{
				room[link.y + 1][link.x] = ' ';
			}
			break;
		case Direction::LEFT:
			if (ReturnSquare(link.y, link.x - 1) == 'O')
			{
				for (int k = 0; k < m_potSize; k++)
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
			if (ReturnSquare(link.y, link.x - 1) == 'J')
			{
				room[link.y][link.x - 1] = ' ';
			}
			break;
		case Direction::RIGHT:
			if (ReturnSquare(link.y, link.x + 1) == 'O')
			{
				for (int k = 0; k < m_potSize; k++)
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
			if (ReturnSquare(link.y, link.x + 1) == 'J')
			{
				room[link.y][link.x + 1] = ' ';
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


