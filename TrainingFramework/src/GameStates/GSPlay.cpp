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
	m_keyB = std::make_shared<Keyboard>();
	DinoChar = std::make_shared<Player>();
	m_Create = std::make_shared<Create>();
}

GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	//auto texture = ResourceManagers::GetInstance()->GetTexture("backgroundplay");

	//BackGround
	auto texture = ResourceManagers::GetInstance()->GetTexture("floor2");
	m_Bg1 = std::make_shared<Background>();
	m_Bg2 = std::make_shared<Background>();

	m_Bg1->Init("floor2", 20);
	m_Bg2->Init("cloud", 40);

	//trex
	texture = ResourceManagers::GetInstance()->GetTexture("dino3");
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	std::shared_ptr<AnimationSprite> dino = std::make_shared<AnimationSprite>(model, shader, texture, 2, 0.1f);
	dino->Set2DPosition(screenWidth - 900, screenHeight / 2);
	dino->SetSize(70, 70);
	m_listAnimation.push_back(dino);

	//bird
	texture = ResourceManagers::GetInstance()->GetTexture("bird1");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	std::shared_ptr<AnimationSprite> bird = std::make_shared<AnimationSprite>(model, shader, texture, 2, 0.2f);
	bird->Set2DPosition(screenWidth / 3, screenHeight / 2);
	bird->SetSize(100, 60);
	m_listAnimation.push_back(bird);

	//text game title
	auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("pixelmix");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TEXT_COLOR::CYAN, 1.0);
	m_score->Set2DPosition(Vector2(800, 50));

	// Button Back
	texture = ResourceManagers::GetInstance()->GetTexture("back2");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 950, screenHeight - 650);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	BackButton.push_back(button);

	//Dino

	DinoChar->GetIdleState()->Init("dino3", 2, 0.1f, 70, 70, Vector2(screenWidth - 900, screenHeight / 2));
	DinoChar->GetDeathState()->Init("death", 2, 0.1f, 62, 39, Vector2(screenWidth - 900, screenHeight / 2));

	DinoChar->GetRunState()->Init("dino3", 2, 0.05f, 44, 35, Vector2(screenWidth - 900, screenHeight / 2));
	DinoChar->GetJumpState()->Init("jump", 2, 0.1f, 36, 43, Vector2(screenWidth - 900, screenHeight / 2));

	// Cactus
	m_Create->GetEnemyCactus()->Init(Enemy::STATE_Run, "Cactus2", 1, 0.1f, 52, 34, Vector2(screenWidth, screenHeight - 69));
	m_Create->GetEnemyCactus()->SetTag(Entity::Tag_EnemyCactus);
	for (auto it : m_Create->GetEnemyCactus()->GetlistEnemy())
	{
		m_check->PushBack(it);
	}
	// bird
	m_Create->GetEnemyBird()->Init(Enemy::STATE_Run, "bird1", 2, 0.1f, 52, 34, Vector2(screenWidth, screenHeight - 69));
	m_Create->GetEnemyBird()->SetTag(Entity::Tag_EnemyBird);
	for (auto it : m_Create->GetEnemyBird()->GetlistEnemy())
	{
		m_check->PushBack(it);
	}
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
	m_keyB->HandleKeyEvents(key, bIsPressed);
	DinoChar->ReciveKeyEvents(m_keyB->GetKey());
}


void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : BackButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSPlay::Update(float deltaTime)
{
	for (auto obj : m_listAnimation)
	{
		obj->Update(deltaTime);
	}
	DinoChar->Update(deltaTime);
}

void GSPlay::Draw()
{
	//m_BackGround->Draw();
	m_Bg1->Draw();
	m_score->Draw();
	for (auto it : BackButton)
	{
		it->Draw();
	}
	for (auto obj : m_listAnimation) {
		obj->Draw();
	}

	DinoChar->Draw();
	m_Create->Draw();

}
