#pragma once
#include "MCState.h"
#include "idle.h"
#include "RunState.h"
#include "JumpState.h"
#include "Death.h"
#include "low.h"

#include "Entity.h"

class Dino :
	public MCState, public Entity
{
public:
	Dino();
	~Dino();
	void SetAction(State::STATE_Action);
	void SetState();
	void SetState(State* newState);
	void SetPos(Vector2 newPos);

	void Init();
	void Draw();
	void Update(float deltaTime);

	State* GetState();
	State* GetJumpState();
	State* GetDeathState();
	State* GetDashState();
	State* GetIdleState();
	State* GetRunState();
	State* GetLowState();

	Vector2* GetPos();
	bool* GetisTouch();
	int* GetSpeed();
	int* GetKeyPress();
	State::STATE_Action* GetCurrentAction();
protected:
	bool m_isTouchTheGround;
	int m_Speed;
	int m_KeyPress;
	State::STATE_Action m_Locked;
	State::STATE_Action m_CurrentAction;

private:
	State* m_CurrentState;
	State* m_JumpState;
	State* m_DeathState;
	State* m_IdleState;
	State* m_RunState;
	State* m_DashState;
	State* m_LowState;

};