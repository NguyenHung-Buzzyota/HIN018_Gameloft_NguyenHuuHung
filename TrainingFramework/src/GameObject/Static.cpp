#include "Static.h"
#include "GameManager/ResourceManagers.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Static::Static() :m_Speed(1000), m_CurrentPos(Vector2(screenWidth / 2, screenHeight / 2)), m_Pos(Vector2(screenWidth / 2, screenHeight / 2))
{
}

Static::Static(int speed) : m_Speed(speed), m_CurrentPos(Vector2(screenWidth / 2, screenHeight / 2)), m_Pos(Vector2(screenWidth / 2, screenHeight / 2))
{
}
Static::Static(int speed, int x, int y) : m_Speed(speed)
{
	m_Pos.x = x;
	m_Pos.y = y;
	m_CurrentPos.x = x;
	m_CurrentPos.y = y;
}
void Static::SetSpeed(int speed)
{
	m_Speed = speed;
}
Static::~Static()
{
}

void Static::Init(std::string NameFile)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture(NameFile);
	m_Image1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_Image2 = std::make_shared<Sprite2D>(model, shader, texture);
	this->SetPostion(screenWidth / 2, screenHeight / 2);
	this->SetSize(screenWidth, screenHeight);
}

void Static::Draw()
{
	m_Image1->Draw();
	m_Image2->Draw();
}

void Static::Update(float deltatime)
{
	m_CurrentPos.x -= m_Speed * deltatime;
	if (m_CurrentPos.x < -m_Pos.x)
	{
		m_CurrentPos.x = m_Pos.x;
	}
	this->SetCurrentPostion(m_CurrentPos.x, m_CurrentPos.y);
}
void Static::SetPostion(int x, int y)
{
	m_Image1->Set2DPosition(x, y);
	m_Image2->Set2DPosition(screenWidth + x, y);
	m_Pos = Vector2(x, y);
	m_CurrentPos = m_Pos;
}

void Static::SetCurrentPostion(int x, int y)
{
	m_Image1->Set2DPosition(x, y);
	m_Image2->Set2DPosition(screenWidth + x, y);
}

void Static::SetSize(int width, int height)
{
	m_Image1->SetSize(width, height);
	m_Image2->SetSize(width, height);
}