#include "Game.h"

Game::Game()
{
	currentScene = Scene::CLASSROOM;
	room.link.m_direction = Direction::UP;
}

void Game::Input(Direction& key)
{
	EnterDoor(key);
	room.MoveLink(key);
	key = Direction::BUG;
}

int* Game::ReadFile(int lineToRead)
{
	std::string width;
	std::string height;
	int size[2];

	std::ifstream roomInfo("config.txt");
	if (roomInfo.is_open())
	{
		for (int i = 0; i < lineToRead; i++)
		{
			std::getline(roomInfo, width, ';');
			std::getline(roomInfo, height, ';');
		}

		roomInfo.close();
	}
	
	size[0] = stoi(width);
	size[1] = stoi(height);
	return size;
}

void Game::GameManager()
{
	int* roomSize;
	switch (currentScene)
	{
	case Scene::START:
		Start();
		break;

	case Scene::CLASSROOM:
		roomSize = ReadFile(1);
		room.CreateRoom(roomSize[0], roomSize[1], 1);
		roomSize = nullptr;
		break;

	case Scene::HALLWAY:
		roomSize = ReadFile(2);
		room.CreateRoom(roomSize[0], roomSize[1], 2);
		roomSize = nullptr;
		break;

	case Scene::CAFE:
		roomSize = ReadFile(3);
		room.CreateRoom(roomSize[0], roomSize[1], 3);
		roomSize = nullptr;
		break;

	case Scene::GAMEOVER:
		GameOver();
		break;

	default:
		break;
	}
}

void Game::EnterDoor(Direction key)
{
	if (room.CheckMovement(key) == 'P')
	{
		if (room.link.m_direction == Direction::UP)
		{
			NextScene();
		}
		else
		{
			PrevScene();
		}
		system("cls");
	}
}

void Game::Start()
{
	std::string startGame;
	std::cout << "Type something to start: ";
	std::cin >> startGame;
	currentScene = (Scene)((int)currentScene + 1);
	system("cls");
}


void Game::GameOver()
{

}

void Game::NextScene()
{
	currentScene = (Scene)((int)currentScene + 1);
}

void Game::PrevScene()
{
	currentScene = (Scene)((int)currentScene - 1);
}


Scene Game::GetCurrentScene() const
{
	return currentScene;
}

Room* Game::GetRoom() 
{
	return &room;
}