#include "GSCredit.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSCredit::GSCredit()
{
}


GSCredit::~GSCredit()
{

}


void GSCredit::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("backgroundmenu");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);
	//Credit
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	TextCredit = std::make_shared< Text>(shader, font, "Game con khung long . Nguyen Huu Hung ", TEXT_COLOR::BLUE, 1.0);
	TextCredit->Set2DPosition(Vector2(10, 100));
}

void GSCredit::Exit()
{

}


void GSCredit::Pause()
{

}

void GSCredit::Resume()
{

}


void GSCredit::HandleEvents()
{

}

void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSCredit::Update(float deltaTime)
{
}

void GSCredit::Draw()
{
	m_BackGround->Draw();

	TextCredit->Draw();

}