//Puissance 4

#include <iostream>

#include "Application.h"

void processEvent(const sf::Event& iEvent)
{
    sf::RenderWindow* window = cApplication::Instance()->GetWindow();

    if (iEvent.type == sf::Event::Closed)
        window->close();
}

void updateWindow(const sf::Time& iElapsedTime)
{
    sf::RenderWindow* window = cApplication::Instance()->GetWindow();
    window->clear();

    sf::RectangleShape rectangle(sf::Vector2f(700.f, 600.f));
    rectangle.setFillColor(sf::Color::Blue);
    window->draw(rectangle);      

    sf::CircleShape circle(45.f);
    circle.setFillColor(sf::Color::White);
    int offset = 5;
    for (int y = 0; y < 6; y++)
    {
        for (int x = 0; x < 7; x++)
        {
            circle.setPosition(sf::Vector2f(offset + x * 100.f, offset + y * 100.f));
            window->draw(circle);
        }
    }

    window->display();
}

int main(int argc, char* argv[])
{
    //Instantiate application
    cApplication* app = cApplication::Instance();

    //Create window and add it to our application
    sf::RenderWindow window(sf::VideoMode(700, 600), "Connect 4");
    app->SetWindow(&window);

    //Set main application delegates
    app->GetOnProcessEventDelegate().Bind(&processEvent);
    app->GetOnUpdateWindowDelegate().Bind(&updateWindow);

    //Run main loop
    app->Run();

    return 0;
}