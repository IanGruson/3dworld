#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
/* #include <GL/gl.h> */
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <math.h>
#include "Renderer.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024


int main(int argc, char *argv[])
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */


		SDL_Window* pWindow = setup_SDL();
		if( pWindow )
		{
			/* SDL_PumpEvents(); //Not needed as it is implicitly called. */
			char cont = 1;
			while(cont!=0)
			{
				/* std::cout << "HELLO" << std::endl; */
				SDL_Event event;
				if(SDL_PollEvent(&event))
				{
					switch(event.type)
					{
						case SDL_KEYUP:
							if(event.key.keysym.sym == SDLK_ESCAPE)
							{
								SDL_DestroyWindow(pWindow);
								/* std::cout << SDLK_ESCAPE << "pressed !" << std::endl; */
								cont = 0;
							}
							break;
						default:
							fprintf(stdout, "Événement non traité : %d\n",event.type);
					}
				}

			}

		}
		else
		{
			fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
		}

		/* SDL_GL_DeleteContext(glcontext); */
	}

	SDL_Quit();
	return 0;
}
