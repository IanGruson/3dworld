#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Camera  
{
	public :
		Camera();
		GLuint cameraShader;
		void processInput(SDL_Event event);
		float cameraX = 0.0f;
		float cameraY = 0.0f;
		float cameraZ = -1.0f;
		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 cameraRight = glm::vec3(glm::cross(cameraUp, cameraDirection));
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

};

