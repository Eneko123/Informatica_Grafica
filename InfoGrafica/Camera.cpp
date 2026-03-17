#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(glm::vec3 startPos, float startYaw, float startPitch, float startMoveSpeed, float startTurnSpeed, glm::vec3 startWorldUp)
{
	pos = startPos;
	worldUp = startWorldUp;
	yaw = startYaw;
	pitch = startPitch;
	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
}

void Camera::update(InputManager& input, float deltaTime)
{
	if (input.isKeyPressed(GLFW_KEY_W)) pos += front * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_A)) pos -= rigth * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_S)) pos -= front * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_D)) pos += rigth * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_Q)) pos += up * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_E)) pos -= up * moveSpeed * deltaTime;

	yaw += input.getMouseDeltaX() * turnSpeed * deltaTime;
	pitch += input.getMouseDeltaY() * turnSpeed * deltaTime;

	if (pitch > 89.9f) pitch = 89.9f;
	if (pitch < -89.9f) pitch = -89.9f;
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(pos, pos + front, up);
}

void Camera::recalculate()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch)) * sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	rigth = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(rigth, worldUp));
}
