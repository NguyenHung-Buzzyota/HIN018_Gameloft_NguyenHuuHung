#pragma once
#include "State.h"

class MCState
{
public:

    virtual void SetAction(State::STATE_Action) = 0;
    virtual void SetState() = 0;
    virtual void SetState(State* StatePtr) = 0;

    virtual State* GetState() = 0;
    virtual State* GetJumpState() = 0;
    virtual State* GetDeathState() = 0;
    virtual State* GetIdleState() = 0;
    virtual State* GetRunState() = 0;
    virtual State* GetDashState() = 0;
    virtual State* GetLowState() = 0;

    virtual Vector2* GetPos() = 0;
    virtual bool* GetisTouch() = 0;
    virtual int* GetSpeed() = 0;
    virtual int* GetKeyPress() = 0;
    virtual State::STATE_Action* GetCurrentAction() = 0;


};