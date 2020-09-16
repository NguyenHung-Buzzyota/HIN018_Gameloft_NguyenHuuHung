#include "Check.h"

void Check::PushBack(std::shared_ptr<Entity> newObj)
{
	m_listObj.push_back(newObj);
}
bool Check::Collising(std::shared_ptr<Entity> obj1, std::shared_ptr<Entity> obj2)
{
	float obj1_up = obj1->GetPos().y - obj1->GetHeight() / 2;
	float obj1_down = obj1->GetPos().y + obj1->GetHeight() / 2;

	float obj2_up = obj2->GetPos().y - obj2->GetHeight() / 2;
	float obj2_down = obj2->GetPos().y + obj2->GetHeight() / 2;

	if (obj1_up > obj2_down) return false;
	if (obj1_down < obj2_up) return false;
	return true;
}

void Check::Detect()
{
	for (auto obj1 : m_listObj)
	{
		if (!obj1->isAlive()) continue;
		for (auto obj2 : m_listObj)
		{
			if (!obj2->isAlive()) continue;
			Entity::Tag tag_obj1 = obj1->GetTag();
			Entity::Tag tag_obj2 = obj2->GetTag();
			if (tag_obj1 == Entity::Tag_Character && ( tag_obj2 == Entity::Tag_EnemyBird || tag_obj2 == Entity::Tag_EnemyCactus))
			{
				if (Collising(obj1, obj2))
				{
					obj1->Death();
					if (tag_obj2 == Entity::Tag_EnemyBird)
					{
						obj2->Death();
					}
				}
			}
			else
				if (tag_obj2 == Entity::Tag_EnemyCactus || tag_obj2 == Entity::Tag_EnemyBird)
				{
					if (Collising(obj1, obj2))
					{
						obj2->Death();
						if (tag_obj1 == Entity::Tag_EnemyBird || tag_obj1 == Entity::Tag_EnemyCactus)
						{
							obj1->Death();
						}
					}
				}
		}
	}
}