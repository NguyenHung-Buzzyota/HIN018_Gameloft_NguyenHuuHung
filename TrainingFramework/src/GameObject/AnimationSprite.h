#pragma once
#include "Sprite2D.h"

class AnimationSprite : public Sprite2D
{
public:
	AnimationSprite();
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, int numFrames, float frameTime);

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
	void		Update2(GLfloat deltatime, bool& isOnFrameStop, bool& isStopAni, int sttFrameStop);
	void		ResetAnimation();

	GLint		GetWidth();
	GLint		GetHeight();
	Vector2* GetPosPtr();
	int			GetCurrentFrame();
	int			GetNumFrame();
protected:
	int m_numFrames;
	float m_frameTime;
	int m_currentFrame;
	float m_currentTime;
};