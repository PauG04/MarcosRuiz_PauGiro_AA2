#include "Game.h"

Game::Game()
{
	currentScene = Scene::CLASSROOM;
}

void Game::Input(Direction& key)
{
	room.MoveLink(key);
	key = Direction::BUG;
}

int Game::ReadFile(int numberToRead)
{
	int i = 0, aux;
	int* arrayNum = new int[numberToRead];

	std::ifstream roomInfo("config.txt");
	if (roomInfo.is_open())
	{
		while (roomInfo >> aux)
		{
			arrayNum[i++] = aux;
		}
		roomInfo.close();
	}

	int num = arrayNum[numberToRead - 1];
	//delete[] arrayNum;
	//arrayNum = nullptr;
	return num;
}

void Game::GameManager()
{
	switch (currentScene)
	{
	case Scene::START:
		Start();
		break;

	case Scene::CLASSROOM:
		room.CreateRoom(ReadFile(1), ReadFile(2));
		break;

	case Scene::HALLWAY:
		room.CreateRoom(ReadFile(3), ReadFile(4));
		break;

	case Scene::CAFE:
		room.CreateRoom(ReadFile(5), ReadFile(6));
		break;

	case Scene::GAMEOVER:
		GameOver();
		break;

	default:
		break;
	}
}

void Game::Play(Direction key)
{
	room.PrintRoom();

	if (room.EnterDoor(key))
	{
		if (room.link.y <= 1)
		{
			NextScene();
		}
		else
		{
			PrevScene();
		}
		system("cls");
	}
	room.MoveLink(key);
	system("cls");
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