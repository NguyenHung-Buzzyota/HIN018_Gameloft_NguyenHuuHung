#pragma once
#include "Static.h"

class Background
{
public:
	Background();
	~Background();
	void		Init(std::string NameFile, int speed);
	void		Draw();
	void		Update(float deltatime);
	void Pause();
	void Resume();
private:
	std::list <std::shared_ptr<Static>> m_BackGround;
	bool m_isPause;
};