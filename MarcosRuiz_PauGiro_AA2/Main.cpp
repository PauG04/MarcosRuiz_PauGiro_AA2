#include "Main.h"

int main()
{
	// CONFIGURATION
	const int FPS = 60;
	bool isPlaying = true;
	

	bool keyboard[static_cast<int>(InputKey::COUNT)] = {};
	InputKey userPressedKey = InputKey::INVALID;

	Game game;
	game.GameManager(userPressedKey);


	// GAME LOOP
	while (isPlaying)
	{
		// INPUT
		keyboard[static_cast<int>(InputKey::K_ESC)] = GetAsyncKeyState(VK_ESCAPE);
		keyboard[static_cast<int>(InputKey::K_LEFT)] = GetAsyncKeyState(VK_LEFT);
		keyboard[static_cast<int>(InputKey::K_RIGHT)] = GetAsyncKeyState(VK_RIGHT);
		keyboard[static_cast<int>(InputKey::K_UP)] = GetAsyncKeyState(VK_UP);
		keyboard[static_cast<int>(InputKey::K_DOWN)] = GetAsyncKeyState(VK_DOWN);
		keyboard[static_cast<int>(InputKey::K_SPACE)] = GetAsyncKeyState(VK_SPACE);
		

		// UPDATE
		game.GameManager(userPressedKey);

		if (keyboard[static_cast<int>(InputKey::K_ESC)])
		{
			userPressedKey = InputKey::K_ESC;
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


		// FRAME CONTROL
		Sleep(1000/FPS);
		system("cls");
	}

	return 0;
}
