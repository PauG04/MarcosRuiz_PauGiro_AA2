#pragma once
#include "Room.h"
#include <fstream>
#include <string>

enum class Scene
{
	INIT_GAME,
	MENU,
	CLASSROOM,
	HALLWAY,
	CAFE,
	GAMEOVER
};

class Game
{
private:
	Scene currentScene;
	Room room;

public:
	Game();

	void GameManager();

	void EnterDoor(Direction key);

	void InitGame();

	void Menu();

	void GameOver();

	void NextScene();

	void PrevScene();

	Scene GetCurrentScene() const;

	Room* GetRoom();

	void Input(Direction& key);

	int* ReadFile(int i);

};



