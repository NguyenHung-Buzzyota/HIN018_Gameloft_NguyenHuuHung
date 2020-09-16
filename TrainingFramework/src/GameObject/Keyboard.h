#pragma once
class Keyboard
{
public:
	enum DKEY
	{
		DKEY_NULL = 0,
		DKEY_UP = 1,
		DKEY_DOWN = 2,
	};

	Keyboard();
	~Keyboard();
	void HandleKeyEvents(int key, bool bIsPressed);
	int GetKey();
protected:
	int KeyPress;
};