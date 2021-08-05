#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
/* #include <GL/gl.h> */
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glx.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024

class Renderer 
{
	public :
	Renderer(unsigned int VBO, Camera *camera, unsigned int screenWidth, unsigned int screenHeight);
	void setup_GL(SDL_Window* window);
	

	private :
	unsigned int VBO, VBA;
	unsigned int screenHeight, screenWidth;
	Camera *camera;

	float vertices[];
};
	SDL_Window* setup_SDL();

#endif
