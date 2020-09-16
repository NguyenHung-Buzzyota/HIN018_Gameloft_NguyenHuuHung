#include "Create.h"

Create::Create()
{
	Cactus = std::make_shared<EnemyManager>(5);
	Bird = std::make_shared<EnemyManager>(5);
	m_BornTime = 2.0f;
	m_deltaSpeed = 10;
	m_CurrentTime = 0.0f;
	m_NumMonster = 1;
}

Create::~Create()
{

}
void Create::Update(float deltaTime)
{
	m_CurrentTime += deltaTime;
	if (m_CurrentTime > m_BornTime)
	{
		for (int i = 0; i < m_NumMonster; i++)
		{
			int x = rand() % 2;
			//switch (x)
			//{
			//case 0:
			//	Cactus->Fire();
			//	break;
			//case 1:
			//	Bird->Fire();
			//	break;
			//default:
			//	break;
			//}
		}
		m_CurrentTime = 0.0f;

	}
	Bird->Update(deltaTime);
	Cactus->Update(deltaTime);

}

void Create::Draw()
{
	Bird->Draw();
	Cactus->Draw();
}

std::shared_ptr<EnemyManager> Create::GetEnemyCactus()
{
	return Cactus;
}
std::shared_ptr<EnemyManager> Create::GetEnemyBird()
{
	return Bird;
}
