#include "Application.h"

#include <iostream>

cApplication::~cApplication()
{
    SDL_Quit();  
}

cApplication::cApplication() :
    mWindow(nullptr),
    mRenderer(nullptr)
{

}

void
cApplication::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
		exit(1);
	}

	mWindow = SDL_CreateWindow("Puissance4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

	if (!mWindow)
	{
		std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

	if (!mRenderer)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
		exit(1);
	}

    SDL_Delay(3000);
}