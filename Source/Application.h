#include "SDL.h"

class cApplication
{
public:
    ~cApplication();
    cApplication();

public:
    SDL_Window* GetWindow() { return mWindow; }
	SDL_Renderer* GetRenderer() { return mRenderer; }

public:
    //Internal
    void Initialize();

private:
    SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};