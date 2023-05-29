#pragma once

#include "Input.h"
#include <iostream>
#include <windows.h>

class Pot
{
private:
	int x, y, potSize;
	int value;

public:

	friend class Room;
};
