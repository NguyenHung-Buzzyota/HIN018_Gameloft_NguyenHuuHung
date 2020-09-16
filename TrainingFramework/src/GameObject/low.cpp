#include "Low.h"


LowState::LowState(MCState* character)
{
	m_Character = character;
	m_currentTime = 0.0f;
}

void LowState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}

void LowState::Draw()
{
	m_Image->Draw();
}

void LowState::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	int keyPress = *m_Character->GetKeyPress();
	int speed = 100;
	Vector2* pos = m_Character->GetPos();
	//Drop

	m_Image->Set2DPosition(*pos);

}

void LowState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void LowState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}

void LowState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void LowState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void LowState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void LowState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void LowState::Low()
{
	m_Character->SetState(m_Character->GetLowState());
}
