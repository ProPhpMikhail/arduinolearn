#pragma once
#include "Light/Led.h"

class IState{
public:
    virtual void setNext(IState* nextState) { _nextState = nextState; }
    virtual IState* next() { return _nextState; }
    virtual void enter() = 0;
    virtual void tick() = 0;
    virtual void exit() = 0;

    virtual ~IState() {}
protected:
    IState* _nextState = nullptr;
};
