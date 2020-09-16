#pragma once
#include "State.h"
#include "MCState.h"

class JumpState :
	public State
{
public:
	JumpState(MCState* character);
	void SetState()
	{
		Dino->SetState(Dino->GetJumpState());
	}

	void Jump();
	void Death();
	void Dash();
	void Idle();
	void Run();

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();

private:
	MCState* Dino;
	std::shared_ptr<AnimationSprite> m_Image;
	float m_currentTime;
};