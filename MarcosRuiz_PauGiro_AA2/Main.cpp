#include "Main.h"

int main()
{
	// CONFIGURATION
	const int FPS = 60;
	bool isPlaying = true;
	Direction userPressedKey = Direction::BUG;
	Game game;
	game.GameManager();
	Scene lastScene = game.GetCurrentScene();

	// GAME LOOP
	while (isPlaying)
	{
		game.GameManager();
		lastScene = game.GetCurrentScene();
		while (lastScene == game.GetCurrentScene())
		{
			lastScene = game.GetCurrentScene();
			game.GetRoom()->PrintRoom();
			while (userPressedKey == Direction::BUG)
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
				else if (GetAsyncKeyState(VK_ESCAPE))
				{
					userPressedKey = Direction::ESCAPE;
				}
			}
			while (userPressedKey != Direction::BUG)
			{
				if (GetAsyncKeyState(VK_ESCAPE) == 0 && userPressedKey == Direction::ESCAPE)
				{
					exit(0);
				}
				else if (GetAsyncKeyState(VK_UP) == 0 && userPressedKey == Direction::UP)
				{
					game.Input(userPressedKey);
				}
				else if (GetAsyncKeyState(VK_DOWN) == 0 && userPressedKey == Direction::DOWN)
				{
					game.Input(userPressedKey);
				}
				else if (GetAsyncKeyState(VK_LEFT) == 0 && userPressedKey == Direction::LEFT)
				{
					game.Input(userPressedKey);
				}
				else if (GetAsyncKeyState(VK_RIGHT) == 0 && userPressedKey == Direction::RIGHT)
				{
					game.Input(userPressedKey);
				}
			}
			Sleep(1000 / FPS);
			system("cls");
		}
		
	}

	return 0;
}
