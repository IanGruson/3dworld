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
#include "Shapes/Cube.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024


int main(int argc, char *argv[])
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Failed initializing SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */

		Camera *cam = new Camera();
		SDL_Window* pWindow = setup_SDL();
		SDL_GLContext glcontext = SDL_GL_CreateContext(pWindow);
		glewExperimental = GL_TRUE;
		glewInit();
		if( pWindow )
		{
			GLuint cameraShader; 
			GLuint cameraProg;
			Program *prog = new Program();
			Camera *cam = new Camera();
			prog->compileShader(cam->cameraShader, prog->cameraShaderSource, GL_SHADER);
			prog->createShaderProgram(cameraProg, cam->cameraShader);
			glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
			view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			prog->setMat4("view", view);
			
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
					cam->processInput(event);
				}
				GLuint VAO, VBO;

				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				Cube *cube = new Cube(VAO, VBO);
				cube->render(prog, VAO);
				SDL_GL_SwapWindow(pWindow);
				
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
