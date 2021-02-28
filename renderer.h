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

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024

class Renderer :
{
	public :
	Renderer(unsigned int VBO, Camera *camera, const unsigned int screenwidth, const unsigned int screenheight);
	void setup_GL(SDL_Window* window);

	private :
	unsigned int VBO, VBA;
	const unsigned int screenheight, screenwidth;
	Camera camera;
}
	SDL_Window setup_SDL();

#endif
