#include "Keyboard.h"

Keyboard::Keyboard()
{
	KeyPress = 0;
}
Keyboard::~Keyboard()
{
}
void Keyboard::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true)
	{
		switch (key)
		{
		case 'W':
			KeyPress |= DKEY_UP;
			break;
		case 'S':
			KeyPress |= DKEY_DOWN;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 'W':
			KeyPress ^= DKEY_UP;
			break;
		case 'S':
			KeyPress ^= DKEY_DOWN;
			break;
		default:
			break;
		}
	}
}
int Keyboard::GetKey()
{
	return KeyPress;
}