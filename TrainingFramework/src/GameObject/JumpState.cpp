#include "JumpState.h"


JumpState::JumpState(MCState* character)
{
	Dino = character;
	m_currentTime = 0.0f;
}

void JumpState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}

void JumpState::Draw()
{
	m_Image->Draw();
}

void JumpState::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	int keyPress = *Dino->GetKeyPress();
	int speed = 100;
	Vector2* pos = Dino->GetPos();
	//Drop
	float ups = 3.0f;
	float s = ups * (speed - 98 * ups * (m_currentTime * m_currentTime / 2.0f)) * deltaTime;

	if (s >= 0)
	{
		pos->y -= s;
		bool isFall = false;
		m_Image->Update2(deltaTime, isFall, isFall, 0);
	}
	m_Image->Set2DPosition(*pos);

}

void JumpState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void JumpState::Jump()
{
	Dino->SetState(Dino->GetJumpState());
}

void JumpState::Death()
{
	Dino->SetState(Dino->GetDeathState());
}
void JumpState::Dash()
{
	Dino->SetState(Dino->GetDashState());
}
void JumpState::Idle()
{
	Dino->SetState(Dino->GetIdleState());
}
void JumpState::Run()
{
	Dino->SetState(Dino->GetRunState());
}
