#include "Game.h"

Game::Game()
{
	ReadConfig();
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

void Game::ReadConfig()
{
	std::string numberToRead;
	std::string numberToRead2;

	std::ifstream roomInfo("config.txt");
	if (roomInfo.is_open())
	{
		for (int i = 0; i < 11; i++)
		{
			if (i == 2 || i == 5 || i == 8)
			{
				std::getline(roomInfo, numberToRead, ';');
				std::getline(roomInfo, numberToRead2, ';');
			}
			else
			{
				std::getline(roomInfo, numberToRead, ';');
			}
			switch (i)
			{
			case 0:
				room.link.SetHearts(stoi(numberToRead));
				break;
			case 1:
				room.ganon.SetHealth(stoi(numberToRead));
				break;
			case 2:
				roomSize[0][0] = stoi(numberToRead);
				roomSize[0][1] = stoi(numberToRead2);
				break;
			case 3:
				numberOfEnemies[0] = (stoi(numberToRead));
				break;
			case 4:
				numberOfPots[0] = (stoi(numberToRead));
				break;
			case 5:
				roomSize[1][0] = stoi(numberToRead);
				roomSize[1][1] = stoi(numberToRead2);
				break;
			case 6:
				numberOfEnemies[1] = (stoi(numberToRead));
				break;
			case 7:
				numberOfPots[1] = (stoi(numberToRead));
				break;
			case 8:
				roomSize[2][0] = stoi(numberToRead);
				roomSize[2][1] = stoi(numberToRead2);
				break;
			case 9:
				numberOfEnemies[2] = (stoi(numberToRead));
				break;
			case 10:
				numberOfPots[2] = (stoi(numberToRead));
				break;
			default:

				break;
			}
		}
		roomInfo.close();
	}
}

void Game::GameManager()
{
	switch (currentScene)
	{
	case Scene::INIT_GAME:
		break;

	case Scene::MENU:
		room.CreatePlayer();
		break;

	case Scene::CLASSROOM:
		room.CreateRoom(roomSize[0][0], roomSize[0][1], 1, numberOfEnemies[0], numberOfPots[0]);
		break;

	case Scene::HALLWAY:
		room.CreateRoom(roomSize[1][0], roomSize[0][1], 2, numberOfEnemies[1], numberOfPots[1]);
		break;

	case Scene::CAFE:
		room.CreateRoom(roomSize[2][0], roomSize[0][1], 3, numberOfEnemies[2], numberOfPots[2]);
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