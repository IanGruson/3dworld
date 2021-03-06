#include "Camera.h"

void Camera::processInput(SDL_Event event)
{
	const float cameraSpeed = 0.5f;
	if(event.key.keysym.sym == SDLK_z)
		cameraPos += cameraSpeed * cameraFront;
	if(event.key.keysym.sym == SDLK_s)
		cameraPos -= cameraSpeed * cameraFront;
	if(event.key.keysym.sym == SDLK_q)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if(event.key.keysym.sym == SDLK_d)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

}
