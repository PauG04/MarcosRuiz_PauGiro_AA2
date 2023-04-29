#include "Game.h"

Game::Game()
{
	currentScene = Scene::CLASSROOM;
}

void Game::GameManager()
{
	switch (currentScene)
	{
	case Scene::START:
		Start();
		break;

	case Scene::CLASSROOM:
		room.CreateRoom(5, 5);
		break;

	case Scene::HALLWAY:
		room.CreateRoom(6, 6);
		break;

	case Scene::CAFE:
		room.CreateRoom(4, 9);
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
		NextScene();
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

Scene Game::GetCurrentScene() const
{
	return currentScene;
}

Room* Game::GetRoom() 
{
	return &room;
}