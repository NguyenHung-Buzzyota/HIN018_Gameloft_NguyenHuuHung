#pragma once
#include "EnemyManager.h"

class Create
{
public:
	Create();
	~Create();
	void Update(float deltaTime);
	void Draw();
	std::shared_ptr<EnemyManager> GetEnemyCactus();
	std::shared_ptr<EnemyManager> GetEnemyBird();


private:
	int m_deltaSpeed;
	float m_BornTime;
	float m_CurrentTime;
	int m_NumMonster;
	std::shared_ptr<EnemyManager> Cactus;
	std::shared_ptr<EnemyManager> Bird;

};