#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}
EnemyManager::~EnemyManager()
{

}
void EnemyManager::Init(Enemy::STATE_Enemy stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	for (auto it : m_listEnemy)
	{
		it->InitForList(model, shader, texture, stt, numFrames, frameTime, width, height, pos);
	}
}

void EnemyManager::SetTag(Entity::Tag newTag)
{
	for (auto it : m_listEnemy)
	{
		it->SetTag(newTag);
	}
}

void EnemyManager::Draw()
{
	for (auto it : m_listEnemy)
	{
		if (it->CheckUsed()) it->Draw();
	}
}

void EnemyManager::Update(float deltaTime)
{
	for (auto it : m_listEnemy)
	{
		if (it->CheckUsed()) it->Update(deltaTime);
	}
}

std::list<std::shared_ptr<Enemy> >EnemyManager::GetlistEnemy()
{
	return m_listEnemy;
}
