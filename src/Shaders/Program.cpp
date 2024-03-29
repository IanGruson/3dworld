#include "Program.h"

Program::Program()
{
}

/**
  Creates a shader, attaches the shader source and proceeds to compile
	the shader.
	@param shaderSource the sourcecode of the shader to create/compile.
 **/
void Program::compileShader(GLuint shader, const char* shaderSource, GLenum shaderType)
{
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	checkCompileErrors(shader, shaderType);
}

/**
	Create a shaderProgram. This method is only used for the camera for now. 
	@param shader the camera shader program.
 **/
void Program::createShaderProgram(GLuint shaderProgram, GLuint shader)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, shader);
	glLinkProgram(shaderProgram);
	
	// Deletes shader after link as there is no use for them anymore. 
	glDeleteShader(shader);
}

/**
  Creates the shader program, and attaches a vertex and a fragment shader. 
  @param vertexShader the vertex shader to attach
  @param fragmentShader the fragment shader to attach
**/
void Program::createShaderProgram(unsigned int shaderProgram, unsigned int vertexShader, unsigned int fragmentShader)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	// Deletes shader after link as there is no use for them anymore. 
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

/**
	Checks for GLSL program compilation errors.
	@param shader the shader to compile.
	@param the type of of program to check (shader or program).
 **/
void Program::checkCompileErrors(GLuint shader, GLenum shaderType)
{
	int  success;
	char infoLog[512];
	if(shaderType == GL_PROGRAM)
	{

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
	if(shaderType == GL_VERTEX_SHADER)
	{

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
	if(shaderType == GL_FRAGMENT_SHADER)
	{

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

}

void Program::setMat4(GLuint shaderProgram, const std::string &name, const glm::mat4 &mat) 
{
	glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
