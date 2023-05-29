#pragma once
#include "Player.h"
#include "Pot.h"
#include "Enemies.h"
#include "Ganon.h"


class Room
{
private:
	char** room;
	int m_width;
	int m_height;
	int m_numberOfPots;
	int m_numberOfEnemies;
	int m_numberOfRoom;
	const std::string player = "\x1b[32m"; //green
	const std::string wall = "\x1b[37m"; //grey
	const std::string door = "\x1b[31m"; //red
	const std::string rupia1 = "\x1b[32m"; //green
	const std::string rupia2 = "\x1b[36m"; //blue
	const std::string rupia3 = "\x1b[31m"; //red
	const std::string potColor = "\x1b[33m"; //yellow
	const std::string enemy = "\x1b[31m"; //red

	Player link;
	Ganon ganon;
	Pot *pot;
	Enemies *enemies;


public:
	int RandomNumber(int max, int min);

	void CreateRoom(const int& width, const int& height, const int& numberOfRoom, const int& numberOfPots, const int& numberOfEnemies);

	void CreatePlayer();

	void CreateEnemies();

	void CreateGanon(const int& width, const int& height);

	void PrintRoom();

	char CheckMovement(const InputKey& key);

	void DestroyRoom();

	void DestroyPot();

	void DestroyEnemy();

	void MoveEnemies();

	bool GanonAlive();

	void GetHitted();

	void SetChars(int numberOfRoom);

	void MoveLink(const InputKey& key);

	void MoveGanon();

	char ReturnSquare(int height, int width);

	Player GetLink();

	void SetPotPosition();

	void SetEnemiesPosition();

	friend class Game;
};

