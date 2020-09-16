#include "Background.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Background::Background()
{
	m_isPause = false;
}
Background::~Background()
{
}
void Background::Init(std::string NameFile, int speed)
{
	auto layer = std::make_shared<Static>(speed);
	layer->Init(NameFile);
	layer->SetPostion(screenWidth / 2, (screenHeight / 2)+30);
	layer->SetSize(1000, 16);
	m_BackGround.push_back(layer);
}

void Background::Draw()
{
	for (auto it : m_BackGround)
	{
		(it)->Draw();
	}
}
void Background::Update(float deltatime)
{
	if (m_isPause) return;
	for (auto it : m_BackGround)
	{
		(it)->Update(deltatime);
	}
}

void Background::Pause()
{
	m_isPause = true;
}
void Background::Resume()
{
	m_isPause = false;
}