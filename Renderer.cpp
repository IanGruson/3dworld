#include "Renderer.h"

Renderer::Renderer(unsigned int VBO, Camera *camera, unsigned int screenWidth, unsigned int screenHeight) 
{
		this->VBO = VBO;
		this->camera = camera;
		this->screenHeight = screenHeight;
		this->screenWidth = screenWidth;
}

SDL_Window* setup_SDL()
{
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_CENTERED,
                                                                  SDL_WINDOWPOS_CENTERED,
                                                                  1280,
                                                                  1024,
                                                                  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS);
		return pWindow;
}

/* void generateTerrain(SDL_Window* window) */
/* { */
/* 	SDL_GLContext glcontext = SDL_GL_CreateContext(window); */
/* 	float vertices[] = { */
/* 		-0.5f, -0.5f, 0.0f, */
/* 		0.5f, -0.5f, 0.0f, */
/* 		-0.0f, 0.5f, 0.0f, */
/* 	}; */
/* 	std::cout << "HELLO" << std::endl; */
	
/* 	const char *vertexShaderSource = "#version 330 core\n" */
/* 		"layout (location = 0) in vec3 aPos;\n" */
/* 		"void main() \n" */
/* 		"{\n" */
/* 		"	gl_position = vec4(aPos.x, aPos.y, aPos.y, 1.0);\n" */
/* 		"};\0"; */
/* 	unsigned int vertexShader; */
/* 	vertexShader = glCreateShader(GL_VERTEX_SHADER); */
/* 	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); */
/* 	glCompileShader(vertexShader); */
/* 	int  success; */
/* 	char infoLog[512]; */
/* 	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); */
/* 	if(!success) */
/* 	{ */
/* 		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); */
/* 		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl; */
/* 	} */

/* 	unsigned int fragmentShader; */
/* 	const char *fragmentShaderSource = "#version 330 core\n" */
/* 		"out vec4 FragColor;\n;" */
/* 		"\n" */
/* 		"void main()\n" */
/* 		"{\n" */
/* 		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" */
/* 		"}\0"; */
/* 	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); */
/* 	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL); */
/* 	glCompileShader(fragmentShader); */

/* 	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success); */
/* 	if(!success) */
/* 	{ */
/* 		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog); */
/* 		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl; */
/* 	} */
/* 	unsigned int shaderProgram; */
/* 	shaderProgram = glCreateProgram(); */
/* 	glAttachShader(shaderProgram, vertexShader); */
/* 	glAttachShader(shaderProgram, fragmentShader); */
/* 	glLinkProgram(shaderProgram); */
/* 	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success); */
/* 	if(!success) */
/* 	{ */
/* 		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog); */
/* 		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl; */
/* 	} */
/* 	glDeleteShader(vertexShader); */
/* 	glDeleteShader(fragmentShader); */
/* 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); */
/* 	glEnableVertexAttribArray(0); */ 

/* 	unsigned int VAO, VBO; */
/* 	glGenBuffers(1, &VBO); */
/* 	glBindBuffer(GL_ARRAY_BUFFER, VBO); */
/* 	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); */
/* 	glGenVertexArrays(1, &VAO); */
/* 	glBindVertexArray(VAO); */
/* 	glDrawArrays(GL_TRIANGLES, 0, 3); */
/* 	SDL_GL_SwapWindow(window); */
/* } */
