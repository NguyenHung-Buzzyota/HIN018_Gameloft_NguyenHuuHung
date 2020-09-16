#pragma once
#pragma once
#include "State.h"
#include "MCState.h"

class LowState :
	public State
{
public:
	LowState(MCState* character);
	void SetState()
	{
		m_Character->SetState(m_Character->GetJumpState());
	}

	void Jump();
	void Death();
	void Dash();
	void Idle();
	void Run();
	void Low();

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();

private:
	MCState* m_Character;
	std::shared_ptr<AnimationSprite> m_Image;
	float m_currentTime;
};