#include "Main.h"

int main()
{
	// CONFIGURATION
	srand(time(NULL));
	const int FPS = 20;
	bool isPlaying = true;
	

	bool keyboard[static_cast<int>(InputKey::COUNT)] = {};
	InputKey userPressedKey = InputKey::INVALID;

	Game game;
	game.GameManager();
	Scene lastScene = game.GetCurrentScene();

	int lastSelectedButton = 1;

	// GAME LOOP
	while (isPlaying)
	{
		if (game.GetRoom() != nullptr)
		{
			game.GetRoom()->DestroyPot();
			game.GetRoom()->DestroyEnemy();
			game.GetRoom()->DestroyRoom();
		}
		game.GameManager();
		lastScene = game.GetCurrentScene();

		while (lastScene == game.GetCurrentScene())
		{
			// INPUT
			keyboard[static_cast<int>(InputKey::K_ESC)] = GetAsyncKeyState(VK_ESCAPE);
			keyboard[static_cast<int>(InputKey::K_LEFT)] = GetAsyncKeyState(VK_LEFT);
			keyboard[static_cast<int>(InputKey::K_RIGHT)] = GetAsyncKeyState(VK_RIGHT);
			keyboard[static_cast<int>(InputKey::K_UP)] = GetAsyncKeyState(VK_UP);
			keyboard[static_cast<int>(InputKey::K_DOWN)] = GetAsyncKeyState(VK_DOWN);
			keyboard[static_cast<int>(InputKey::K_SPACE)] = GetAsyncKeyState(VK_SPACE);


			// UPDATE
			lastScene = game.GetCurrentScene();

			if (keyboard[static_cast<int>(InputKey::K_ESC)])
			{
				exit(0);
			}
			else if (keyboard[static_cast<int>(InputKey::K_LEFT)])
			{
				userPressedKey = InputKey::K_LEFT;
			}
			else if (keyboard[static_cast<int>(InputKey::K_RIGHT)])
			{
				userPressedKey = InputKey::K_RIGHT;
			}
			else if (keyboard[static_cast<int>(InputKey::K_UP)])
			{
				userPressedKey = InputKey::K_UP;
			}
			else if (keyboard[static_cast<int>(InputKey::K_DOWN)])
			{
				userPressedKey = InputKey::K_DOWN;
			}
			else if (keyboard[static_cast<int>(InputKey::K_SPACE)])
			{
				userPressedKey = InputKey::K_SPACE;
			}

			// RENDER
			game.Input(userPressedKey);

			switch (game.GetCurrentScene())
			{                         
			case Scene::INIT_GAME:
				game.InitGame();
				break;
			case Scene::MENU:
				if (game.Menu(userPressedKey, lastSelectedButton))
					exit(0);
				break;
			case Scene::CLASSROOM:
				game.GetRoom()->PrintRoom();
				break;
			case Scene::HALLWAY:
				game.GetRoom()->PrintRoom();
				break;
			case Scene::CAFE:
				game.GetRoom()->PrintRoom();
				if (!game.GetRoom()->GanonAlive())
					game.GameOver(true);
				break;
			case Scene::GAMEOVER:
				exit(0);
				break;
			default:
				break;
			}

			// FRAME CONTROL
			Sleep(1000 / FPS);
			system("cls");

			// RESET
			userPressedKey = InputKey::INVALID;
		}
		
	}

	return 0;
}
