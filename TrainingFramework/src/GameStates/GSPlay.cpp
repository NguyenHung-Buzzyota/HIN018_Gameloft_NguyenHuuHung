#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "AnimationSprite.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("backgroundplay");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	// Button Back
	texture = ResourceManagers::GetInstance()->GetTexture("back2");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 950, screenHeight - 650);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//T-rex animation
	texture = ResourceManagers::GetInstance()->GetTexture("dino3");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	std::shared_ptr<AnimationSprite> dino = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.5f);
	dino->Set2DPosition(screenWidth / 3, screenHeight*2 / 3);
	dino->SetSize(47, 47);
	m_listAnimation.push_back(dino);

}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSPlay::Update(float deltaTime)
{
}

void GSPlay::Draw()
{
	m_BackGround->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto obj : m_listAnimation) {
		obj->Draw();
	}
}

void GSPlay::SetNewPostionForBullet()
{

}