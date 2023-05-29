#include "Game.h"

Game::Game()
{
	currentScene = Scene::INIT_GAME;
	room.link.SetDirection(Direction::UP);
}

void Game::Input(const InputKey& key)
{
	if (currentScene == Scene::CLASSROOM || currentScene == Scene::HALLWAY || currentScene == Scene::CAFE)
	{
		EnterDoor(key);
		room.MoveLink(key);
		if (timer == 5)
		{
			room.MoveEnemies();
			room.MoveGanon();
			room.GetHitted();
			if (room.link.GetHearts() <= 0)
				GameOver(false);
			timer = -1;
		}
		timer++;
	}
}

int Game::ReadConfig(int lineToRead)
{
	std::string numberRead;
	std::string notUsed;

	std::ifstream roomInfo("config.txt");
	if (roomInfo.is_open())
	{
		for (int i = 0; i < lineToRead; i++)
		{
			if (i == 2 || i == 5 || i == 8)
			{
				std::getline(roomInfo, notUsed, ';');
				std::getline(roomInfo, notUsed, ';');
			}
			else
				std::getline(roomInfo, numberRead, ';');
		}
		roomInfo.close();
		return stoi(numberRead);
	}
	return -1;
}

std::vector<int> Game::ReadRoomSize(int lineToRead)
{
	std::string width;
	std::string height;
	std::string notUsed;

	std::ifstream roomInfo("config.txt");
	if (roomInfo.is_open())
	{
		for (int i = 0; i < lineToRead; i++)
		{
			if (i == 2 || i == 5 || i == 8)
			{
				std::getline(roomInfo, width, ';');
				std::getline(roomInfo, height, ';');
			}
			else
				std::getline(roomInfo, notUsed, ';');
		}
		roomInfo.close();
		std::vector<int> size{ 2, 0 };
		size[0] = stoi(width);
		size[1] = stoi(height);
		return size;
	}
	std::vector<int> size{ 2, -1 };
	return size;		
}

void Game::GameManager()
{
	std::vector<int> roomSize;
	int numberOfEnemies;
	int numberOfPots;
	switch (currentScene)
	{
	case Scene::INIT_GAME:
		break;

	case Scene::MENU:
		room.CreatePlayer(ReadConfig(1));
		break;

	case Scene::CLASSROOM:
		roomSize = ReadRoomSize(3);
		numberOfEnemies = ReadConfig(4);
		numberOfPots = ReadConfig(5);
		room.CreateRoom(roomSize[0], roomSize[1], 1, numberOfEnemies, numberOfPots);
		break;

	case Scene::HALLWAY:
		roomSize = ReadRoomSize(6);
		numberOfEnemies = ReadConfig(7);
		numberOfPots = ReadConfig(8);
		room.CreateRoom(roomSize[0], roomSize[1], 2, numberOfEnemies, numberOfPots);
		break;

	case Scene::CAFE:
		roomSize = ReadRoomSize(9);
		numberOfEnemies = ReadConfig(10);
		numberOfPots = ReadConfig(11);
		room.CreateGanon(ReadConfig(2));
		room.CreateRoom(roomSize[0], roomSize[1], 3, numberOfEnemies, numberOfPots);	
		break;

	case Scene::GAMEOVER:
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
			room.DestroyPot();
			//room.DestroyEnemy();
		}
		else
		{
			PrevScene();
			room.DestroyPot();
			//room.DestroyEnemy();
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

void Game::GameOver(bool win)
{
	system("cls");
	currentScene = Scene::GAMEOVER;

	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 32);

	std::string messageGameOver;
	std::string messageGameOver2;
	if (win)
	{
		messageGameOver = "YOU WIN!";
		messageGameOver2 = "YOU HAVE DEFEATED GANON! YOU'LL BE SAFE, AT LEAST FOR THIS YEAR...";
	}
	else
	{
		messageGameOver = "YOU LOSE";
		messageGameOver2 = "GANON DEFEATED YOU! GOOD LUCK RETAKING THE COURSE...";
	}

	std::cout << "************************************************************" << std::endl;
	std::cout << "************************ " << messageGameOver << " **************************" << std::endl;
	std::cout << "************************************************************" << std::endl;

	SetConsoleTextAttribute(console_color, 15);

	std::cout << std::endl << messageGameOver2 << std::endl << std::endl;
	std::cout << "A GAME MADE BY PAU GIRO & MARCOS RUIZ";

	Sleep(5000);
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