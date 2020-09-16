#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "Background.h"
#include "Keyboard.h"
#include "Dino.h"
#include "Application.h"
#include "Check.h"
#include "player.h"
#include "Create.h"
#include "AnimationSprite.h"

class Sprite2D;
class Sprite3D;
class Text;
class AnimationSprite;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();


private:

	
	std::shared_ptr<Text>  m_score;
	std::list<std::shared_ptr<GameButton>>	BackButton;
	std::vector<std::shared_ptr<AnimationSprite>> m_listAnimation;

	std::shared_ptr<Player> DinoChar;
	
	std::shared_ptr<Create> m_Create;
	std::shared_ptr<Background> m_Bg1;
	std::shared_ptr<Background> m_Bg2;

	std::shared_ptr<Keyboard> m_keyB;

	std::shared_ptr<Check> m_check;

};

