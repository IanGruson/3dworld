#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL2/SDL.h>
#include "../Shaders/Program.h"
#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glx.h>

class Cube
{
	public :
		Cube();
		unsigned int VBO, VAO;
		void render(Program *program);
		float vertices[]; 
	private :
};
