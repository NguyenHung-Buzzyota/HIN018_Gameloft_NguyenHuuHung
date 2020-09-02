#pragma once
#include "Sprite2D.h"

class AnimationSprite : public Sprite2D
{
public:
	AnimationSprite();
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, int numFrame,float frameTime);
	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
protected:
	int m_numFrame;
	float m_frameTime;
	int m_curentFrame;
	float m_curentTime;
};