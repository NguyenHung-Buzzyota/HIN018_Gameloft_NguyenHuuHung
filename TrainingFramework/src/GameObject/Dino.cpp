#include "Dino.h"

Dino::Dino()
{
	m_JumpState = new JumpState(this);
	m_DeathState = new DeathState(this);
	m_IdleState = new IdleState(this);
	m_RunState = new RunState(this);
	m_LowState = new LowState(this);
	m_CurrentState = m_IdleState;

	m_isTouchTheGround = false;

	m_Pos = Vector2(100, 100);
	SetTag(Entity::Tag_Character);
}

Dino::~Dino()
{
	if (m_IdleState != nullptr)
	{
		delete m_IdleState;
		m_IdleState = nullptr;
	}
	if (m_RunState != nullptr)
	{
		delete m_RunState;
		m_RunState = nullptr;
	}
	if (m_DeathState != nullptr)
	{
		delete m_DeathState;
		m_DeathState = nullptr;
	}
	if (m_JumpState != nullptr)
	{
		delete m_JumpState;
		m_JumpState = nullptr;
	}
	if (m_LowState != nullptr)
	{
		delete m_LowState;
		m_LowState = nullptr;
	}
	m_CurrentState = nullptr;
}
void Dino::SetPos(Vector2 newPos)
{
	m_Pos = newPos;
}
Vector2* Dino::GetPos()
{
	return &m_Pos;
}
bool* Dino::GetisTouch()
{
	return &m_isTouchTheGround;
}
int* Dino::GetSpeed()
{
	return &m_Speed;
}
int* Dino::GetKeyPress()
{
	return &m_KeyPress;
}
State::STATE_Action* Dino::GetCurrentAction()
{
	return &m_CurrentAction;
}

void Dino::SetAction(State::STATE_Action stt)
{
	if (m_Locked == stt) return;
	m_Locked = stt;
	m_CurrentState->ResetAnimation();

	switch (stt)
	{
	case State::STATE_Idle:
		m_CurrentState->Idle();
		break;
	case State::STATE_Run:
		m_CurrentState->Run();
		break;
	case State::STATE_Death:
		m_CurrentState->Death();
		break;
	case State::STATE_Jump:
		m_CurrentState->Jump();
		break;
	case State::STATE_Low:
		m_CurrentState->Low();
	default:
		break;
	}
}

void Dino::SetState()
{
	m_CurrentState->SetState();
}

void Dino::SetState(State* newState)
{
	m_CurrentState = newState;
}

void Dino::Init()
{

}
void Dino::Draw()
{
	m_CurrentState->Draw();
}
void Dino::Update(float deltaTime)
{
	if (m_Alive) SetAction(m_CurrentAction);
	else
	{
		SetAction(State::STATE_Death);
	}
	m_CurrentState->Update(deltaTime);
	Entity::SetPos(m_Pos);
}

State* Dino::GetState()
{
	return m_CurrentState;
}
State* Dino::GetJumpState()
{
	return m_JumpState;
}

State* Dino::GetDeathState()
{
	return m_DeathState;
}
State* Dino::GetIdleState()
{
	return m_IdleState;
}
State* Dino::GetRunState()
{
	return m_RunState;
}
State* Dino::GetLowState()
{
	return m_LowState;
}


