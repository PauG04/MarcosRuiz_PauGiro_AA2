#include "Main.h"

int main()
{
	// CONFIGURATION
	bool isPlaying = true;
	bool userPressedKey = false;
	Game game;
	Scene sameScene = Scene::CLASSROOM;

	// GAME LOOP
	while (isPlaying)
	{
		game.GameManager();
		while (sameScene == game.GetCurrentScene())
		{
			sameScene = game.GetCurrentScene();

			game.GetRoom().PrintRoom();

			while (!userPressedKey)
			{
				if (GetAsyncKeyState(VK_UP))
				{
					userPressedKey = true;
					if (game.GetRoom().EnterDoor(Direction::UP))
					{
						game.NextScene();
						system("cls");
					}
					else
						game.GetRoom().MoveLink(Direction::UP);

				}
				if (GetAsyncKeyState(VK_DOWN))
				{
					userPressedKey = true;
					if (game.GetRoom().EnterDoor(Direction::DOWN))
					{
						game.NextScene();
						system("cls");
					}
					else
						game.GetRoom().MoveLink(Direction::DOWN);
				}
				if (GetAsyncKeyState(VK_LEFT))
				{
					userPressedKey = true;
					if (game.GetRoom().EnterDoor(Direction::LEFT))
					{
						game.NextScene();
						system("cls");
					}
					else
						game.GetRoom().MoveLink(Direction::LEFT);
				}
				if (GetAsyncKeyState(VK_RIGHT))
				{
					userPressedKey = true;
					if (game.GetRoom().EnterDoor(Direction::RIGHT))
					{
						game.NextScene();
						system("cls");
					}
					else
						game.GetRoom().MoveLink(Direction::RIGHT);
				}
			}
			userPressedKey = false;
			system("cls");
		}
	}

	return 0;
}
