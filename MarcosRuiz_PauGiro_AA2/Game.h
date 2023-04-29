#pragma once
#include "Room.h"

enum class Scene
{
	START,
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

	void Play(Direction key);

	void Start();

	void GameOver();

	void NextScene();

	Scene GetCurrentScene() const;

	Room* GetRoom();

};



