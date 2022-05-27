#pragma once

#include <SFML/Graphics.hpp>
#include "Delegate.h"

class cApplication
{
public:
    typedef TDelegate<void, const sf::Time&> tOnUpdateWindowDelegate;
    typedef TDelegate<void, const sf::Event&> tOnProcessEventDelegate;

private:
    ~cApplication();
    cApplication();

public:
    static cApplication* Instance();

public:
    //Runs the application main loop
    void Run();

public:
    //Getters
    sf::RenderWindow* GetWindow();

    tOnUpdateWindowDelegate& GetOnUpdateWindowDelegate();
    tOnProcessEventDelegate& GetOnProcessEventDelegate();

public:
    //Setters
    void SetWindow(sf::RenderWindow* iWindow);

private:
    sf::RenderWindow* mWindow;

    tOnUpdateWindowDelegate mOnUpdateWindowDelegate;
    tOnProcessEventDelegate mOnProcessEventDelegate;
};