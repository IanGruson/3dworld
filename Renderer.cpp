#include "Renderer.h"

Renderer::Renderer(unsigned int VBO, Camera *camera, unsigned int screenWidth, unsigned int screenHeight) 
{
		this->VBO = VBO;
		this->camera = camera;
		this->screenHeight = screenHeight;
		this->screenWidth = screenWidth;
}

SDL_Window* setup_SDL()
{
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_CENTERED,
                                                                  SDL_WINDOWPOS_CENTERED,
                                                                  1280,
                                                                  1024,
                                                                  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS);
		return pWindow;
}


