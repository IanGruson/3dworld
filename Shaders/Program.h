#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glx.h>

class Program
{
	public : 
		Program();
		void compileShader(unsigned int shader, const char* shaderSource, GLenum shaderType);
		void shaderProgram(unsigned int shaderProgram, unsigned int vertexShader, unsigned int fragmentShader);
		void checkCompileErrors(GLuint shader, GLenum shaderType);
		const char *vertexShaderSource = "#version 460 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";
		const char *fragmentShaderSource = "#version 460 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";

};