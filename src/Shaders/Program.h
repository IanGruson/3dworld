#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glx.h>
#include <glm/glm.hpp>

class Program
{
	public : 
		Program();
		GLuint fragmentShader;
		GLuint vertexShader;
		GLuint shaderProgram;
		void compileShader(GLuint shader, const char* shaderSource, GLenum shaderType);
		void createShaderProgram(GLuint shaderProgram, GLuint shader);
		void createShaderProgram(GLuint shaderProgram, GLuint vertexShader, GLuint fragmentShader);
		void checkCompileErrors(GLuint shader, GLenum shaderType);
		void setMat4(GLuint shaderProgram, const std::string &name, const glm::mat4 &mat);
		const char *vertexShaderSource = "#version 460 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec2 aTexCoord;\n"
			"\n"
			"out vec2 TexCoord;\n"
			"\n"
			"uniform mat4 model;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"
			"\n"
			"void main()\n"
			"{\n"
			"gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
			"TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
			"}\n\0";
		const char *fragmentShaderSource = "#version 460 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";




};
