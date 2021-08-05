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
#include <assert.h>     /* assert */
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
			Camera *cam = new Camera();

			GLuint VAO, VBO;

			Cube *cube = new Cube(VAO, VBO);
			glBindVertexArray(VAO);

			glUseProgram(shaderProgram);
			
			GLint infoLogLength;
			int projectionLocation = glGetUniformLocation(shaderProgram, "u_projection");
			if(projectionLocation == -1) {

				glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
				// Get the info log
				std::cout << "uniform location returned -1 for u_projection" << std::endl;
				GLchar* infoLog = new GLchar[infoLogLength];
				glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, infoLog);
				std::cout << "infoLog is : " << infoLog << std::endl;
				exit(1);
			}

			else {
			prog->setMat4(shaderProgram, "u_projection", projection);
			}

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

					/* Must bind program using glUseProgram & also
					 * glBindVertexArray before modifying the uniform values.
					 * */

					/* glBindVertexArray(VAO); */
					prog->setMat4(shaderProgram, "u_view", view);
					prog->setMat4(shaderProgram, "u_model", model);

					GLint viewLocation = glGetUniformLocation(shaderProgram, "u_view");
					std::cout << "view location returns : " << viewLocation << std::endl;

					GLint modelLocation = glGetUniformLocation(shaderProgram, "u_model");
					std::cout << "model location returns : " << modelLocation << std::endl;

					GLint projectionLocation = glGetUniformLocation(shaderProgram, "u_projection");
					std::cout << "projection location returns : " << projectionLocation << std::endl;

					glDrawArrays(GL_TRIANGLES, 0, 36);

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
