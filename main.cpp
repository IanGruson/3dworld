#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
/* #include <GL/gl.h> */
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
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
			/* Creating our shader program. */
			Program *prog = new Program();
			GLuint shaderProgram;
			prog->compileShader(prog->vertexShader, prog->vertexShaderSource, GL_SHADER);
			prog->compileShader(prog->fragmentShader, prog->fragmentShaderSource, GL_FRAGMENT_SHADER);
			prog->createShaderProgram(shaderProgram,prog->vertexShader, prog->fragmentShader);

			/* Initializing view, model and projection matrices. */ 
			glm::mat4 projection = glm::mat4(1.0f);
			projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT, 0.1f, 100.0f);

			glm::mat4 model = glm::mat4(1.0f);
			model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 

			glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

			glUseProgram(shaderProgram);
			prog->setMat4(shaderProgram, "projection", projection);

			Camera *cam = new Camera();

			GLuint VAO, VBO;

			Cube *cube = new Cube(VAO, VBO);

			
			/* This is the main rendering loop. */
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
							/* default: */
							/* 	fprintf(stdout, "Événement non traité : %d\n",event.type); */
					}

					/* This moves the camera by changing the view uniform vec in */ 
					/* 	our vertex shader. */
					cam->processInput(event);
					view = glm::lookAt(cam->cameraPos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
					/* std::cout << glm::to_string(view) << std::endl; */
					std::cout << glm::to_string(cam->cameraPos) << std::endl;

					/* Must render (glUseProgram & glBindVertexArray) before modifying the uniform values. */
					/* cube->render(shaderProgram, VAO); */
					glDrawArrays(GL_TRIANGLES, 0, 36);

					prog->setMat4(shaderProgram, "view", view);
					prog->setMat4(shaderProgram, "model", model);
					glBindVertexArray(VAO);

					GLint viewLocation = glGetUniformLocation(shaderProgram, "view");
					std::cout << "view location returns : " << viewLocation << std::endl;

					GLint modelLocation = glGetUniformLocation(shaderProgram, "model");
					std::cout << "model location returns : " << modelLocation << std::endl;

					GLint projectionLocation = glGetUniformLocation(shaderProgram, "projection");
					std::cout << "projection location returns : " << projectionLocation << std::endl;

					glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
					/* glClear(GL_COLOR_BUFFER_BIT); */
					SDL_GL_SwapWindow(pWindow);
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
