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

	void GameManager(const InputKey& key);

	void EnterDoor(const InputKey& key);

	void InitGame();

	void Menu(const InputKey& key);

	void GameOver();

	void NextScene();

	void PrevScene();

	Scene GetCurrentScene() const;

	Room* GetRoom();

	void Input(const InputKey& key);

	int* ReadFile(int i);

};



