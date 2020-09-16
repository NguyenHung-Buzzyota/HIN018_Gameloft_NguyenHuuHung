#pragma once
#include "Dino.h"

class Player :
	public Dino
{
public:
	Player();
	~Player();

	void Init(int width, int height, Vector2 pos);
	void ReciveKeyEvents(int key);

	void Update(float deltaTime);
};