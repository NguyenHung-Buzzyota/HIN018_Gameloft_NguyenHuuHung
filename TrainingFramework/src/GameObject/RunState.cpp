#include "RunState.h"


RunState::RunState(MCState* character)
{
	m_Character = character;
}

void RunState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void RunState::Draw()
{
	m_Image->Draw();
}

void RunState::Update(float deltaTime)
{

	int keyPress = *m_Character->GetKeyPress();
	int speed = *m_Character->GetSpeed();
	Vector2* pos = m_Character->GetPos();


	m_Image->Set2DPosition(*pos);
	if (keyPress & Keyboard::DKEY_UP)
	{
		*m_Character->GetCurrentAction() = State::STATE_Jump;
	}
	else if (keyPress & Keyboard::DKEY_DOWN)
	{
		*m_Character->GetCurrentAction() = State::STATE_Dash;
	}

	m_Image->Update(deltaTime);
}

void RunState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void RunState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}

void RunState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void RunState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void RunState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void RunState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
