#include "Game.h"

Game::Game()
{
	currentScene = Scene::INIT_GAME;
	room.link.m_direction = Direction::UP;
}

void Game::Input(const InputKey& key)
{
	if (currentScene == Scene::CLASSROOM || currentScene == Scene::HALLWAY || currentScene == Scene::CAFE)
	{
		EnterDoor(key);
		room.MoveLink(key);
	}
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
	case Scene::INIT_GAME:
		break;

	case Scene::MENU:
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

void Game::EnterDoor(const InputKey& key)
{
	if (room.CheckMovement(key) == 'P')
	{
		if (key == InputKey::K_UP)
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

void Game::InitGame()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 32);

	std::cout << "************************************************************" << std::endl;
	std::cout << "** THE  LEGEND  OF  ZELDA:  TEARS  OF  THE  ENTI  KINGDOM **" << std::endl;
	std::cout << "************************************************************" << std::endl;

	Sleep(3000);
	SetConsoleTextAttribute(console_color, 15);
	system("cls");
	NextScene();
}

bool Game::Menu(const InputKey& key, int& last)
{
	int selectedButton = last;
	char button1;
	char button2;

	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 32);

	std::cout << "************************************************************" << std::endl;
	std::cout << "************************ MAIN  MENU ************************" << std::endl;
	std::cout << "************************************************************" << std::endl;
	
	SetConsoleTextAttribute(console_color, 15);

	if (key == InputKey::K_UP)
		selectedButton = 1;
	else if (key == InputKey::K_DOWN)
		selectedButton = 2;
	else if (key == InputKey::K_SPACE && selectedButton == 2)
		return true;
	else if (key == InputKey::K_SPACE)
	{
		NextScene();
		return false;
	}
		
	last = selectedButton;

	if (selectedButton == 1)
	{
		button1 = '>';
		button2 = ' ';
	}
	else
	{
		button1 = ' ';
		button2 = '>';
	}
	
	std::cout << "                     " << button1 <<" 0. Play Game" << std::endl;
	std::cout << "                     " << button2 <<" 1. Exit" << std::endl;

	return false;
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