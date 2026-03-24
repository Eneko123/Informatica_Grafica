#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Light
{
public:
	Light();
	Light(glm::vec3 color, float ambienteInstensity);
	void UseLight(GLfloat colorLocation, GLfloat aInstesityLocation);
	~Light();
private:
	glm::vec3 color;
	GLfloat aIntensity;
};

