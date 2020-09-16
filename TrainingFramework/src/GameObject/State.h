#pragma once

#include "AnimationSprite.h"
#include "ResourceManagers.h"
#include "keyBoard.h"


class State
{
public:
	enum STATE_Action
	{
		STATE_Idle = 0,
		STATE_Run,
		STATE_Death,
		STATE_Jump,
		STATE_Dash,
		STATE_Low,
	};
	virtual void SetState() = 0;

	virtual void Jump() = 0;
	virtual void Death() = 0;
	virtual void Idle() = 0;
	virtual void Run() = 0;
	virtual void Dash() = 0;
	virtual void Low() = 0;

	virtual void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos) = 0;
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;

	virtual void ResetAnimation() = 0;

};