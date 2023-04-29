#include "Main.h"

void input(Direction& key, Game& game)
{	
	game.GetRoom()->MoveLink(key);
	key = Direction::BUG;
}

int main()
{
	// CONFIGURATION
	const int FPS = 60;
	bool isPlaying = true;
	Direction userPressedKey = Direction::BUG;
	Game game;
	Scene sameScene = Scene::CLASSROOM;
	game.GameManager();

	// GAME LOOP
	while (isPlaying)
	{
		game.GetRoom()->PrintRoom();
		if (userPressedKey == Direction::BUG)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				userPressedKey = Direction::UP;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				userPressedKey = Direction::DOWN;
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				userPressedKey = Direction::LEFT;
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				userPressedKey = Direction::RIGHT;
			}
		}
		if (userPressedKey != Direction::BUG)
		{
			if (GetAsyncKeyState(VK_UP) == 0 && userPressedKey == Direction::UP)
			{
				input(userPressedKey, game);
			}
			else if (GetAsyncKeyState(VK_DOWN) == 0 && userPressedKey == Direction::DOWN)
			{
				input(userPressedKey, game);
			}
			else if (GetAsyncKeyState(VK_LEFT) == 0 && userPressedKey == Direction::LEFT)
			{
				input(userPressedKey, game);
			}
			else if (GetAsyncKeyState(VK_RIGHT) == 0 && userPressedKey == Direction::RIGHT)
			{
				input(userPressedKey, game);
			}

		}
		Sleep(1000 / FPS);
		system("cls");
	}

	return 0;
}
