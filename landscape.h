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

void generateTerrain(SDL_Window* window);
#endif
