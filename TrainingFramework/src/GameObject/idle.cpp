#include "idle.h"


IdleState::IdleState(MCState* character)
{
	m_Character = character;
}

void IdleState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void IdleState::Draw()
{

	m_Image->Draw();
}

void IdleState::Update(float deltaTime)
{
	m_Image->Set2DPosition(*m_Character->GetPos());
	m_Image->Update(deltaTime);
}
void IdleState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void IdleState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}

void IdleState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void IdleState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void IdleState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void IdleState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
