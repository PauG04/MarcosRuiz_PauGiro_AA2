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

	void PrevScene();

	Scene GetCurrentScene() const;

	Room* GetRoom();

	void Input(Direction& key);

};



