#pragma once
#include "Player.h"
#include "Pot.h"
#include "Enemies.h"


class Room
{
private:
	char** room;
	int m_width;
	int m_height;
	int m_potSize;
	int m_enemies;
	const std::string player = "\x1b[32m"; //green
	const std::string wall = "\x1b[37m"; //grey
	const std::string door = "\x1b[31m"; //red
	const std::string rupia1 = "\x1b[32m"; //green
	const std::string rupia2 = "\x1b[36m"; //blue
	const std::string rupia3 = "\x1b[31m"; //red
	const std::string potColor = "\x1b[33m"; //yellow
	const std::string enemy = "\x1b[31m"; //red

	Player link;
	Pot *pot;
	Enemies *enemies;


public:
	int RandomNumber(int max, int min);

	void CreateRoom(const int& width, const int& height, int numberOfRoom);

	void CreatePlayer(const int& hearts);

	void PrintRoom();

	char CheckMovement(const InputKey& key);

	void DestroyRoom();

	void DestroyPot();

	void MoveLink(const InputKey& key);

	char ReturnSquare(int height, int width);

	Player GetLink();

	void SetPotPosition(const int& width, const int& height, const int& size, Pot pot[], Player link);

	void SetEnemiesPosition(const int& width, const int& height, const int& size, Pot pot[], Player link, Enemies enemy[], const int& potSize);

	friend class Game;
};

