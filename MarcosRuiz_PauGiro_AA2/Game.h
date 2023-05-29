#pragma once
#include "Room.h"
#include <fstream>
#include <string>
#include <vector>

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
	int timer;
	int roomSize[3][2];
	int numberOfEnemies[3];
	int numberOfPots[3];


public:
	Game();

	void GameManager();

	void EnterDoor(const InputKey& key);

	void InitGame();

	bool Menu(const InputKey& key, int& last);

	void GameOver(bool win);

	void NextScene();

	void PrevScene();

	Scene GetCurrentScene() const;

	Room* GetRoom();

	void Input(const InputKey& key);

	void ReadConfig();

};



