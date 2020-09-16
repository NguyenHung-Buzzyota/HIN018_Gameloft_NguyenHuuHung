#include "player.h"
#include "Keyboard.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Player::Player()
{
	m_KeyPress = 0;
	m_Speed = 150;
}
Player::~Player()
{

}
void Player::Init(int width, int height, Vector2 pos)
{
	m_Pos = pos;
}

void Player::ReciveKeyEvents(int key)
{
	m_KeyPress = key;
}
#define PLANE screenHeight

void Player::Update(float deltaTime)
{
	if (m_Pos.y >= PLANE)
	{
		m_isTouchTheGround = true;
	}
	else m_isTouchTheGround = false;
	Dino::Update(deltaTime);
}