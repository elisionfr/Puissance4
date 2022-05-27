#pragma once

#include "Application.h"

cApplication::~cApplication()
{
}

cApplication::cApplication() :
    mWindow(nullptr)
{
}

cApplication*
cApplication::Instance()
{
    static cApplication* instance = new cApplication();
    return instance;
}

void
cApplication::Run()
{
    //Main Loop
    sf::Event event;
    sf::Clock clock;
    float framesPerSecond = 60.f;
    sf::Time timePerFrame = sf::seconds(1.f/framesPerSecond);

    while(mWindow->isOpen())
    {
        //Manage events
        if (!mWindow->pollEvent(event))
            continue;

        if (mOnProcessEventDelegate.IsBound())
            mOnProcessEventDelegate.Execute(event);

        if (mWindow->isOpen() && clock.getElapsedTime() < timePerFrame)
            continue;

        //Update Window
        sf::Time elapsedTime = clock.restart();
        if (mOnUpdateWindowDelegate.IsBound())
            mOnUpdateWindowDelegate.Execute(elapsedTime);
    }
}

void
cApplication::SetWindow(sf::RenderWindow* iWindow)
{
    mWindow = iWindow;
}

sf::RenderWindow*
cApplication::GetWindow()
{
    return mWindow;
}

cApplication::tOnUpdateWindowDelegate&
cApplication::GetOnUpdateWindowDelegate()
{
    return mOnUpdateWindowDelegate;
}

cApplication::tOnProcessEventDelegate&
cApplication::GetOnProcessEventDelegate()
{
    return mOnProcessEventDelegate;
}