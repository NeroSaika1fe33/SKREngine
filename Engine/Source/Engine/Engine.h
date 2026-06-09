#pragma once


class Engine
{
public:
    virtual void preInit();
    virtual void Init();
    virtual void PostInit();
    virtual void Tick();
    virtual void preExit();
    virtual void Exit();
};
