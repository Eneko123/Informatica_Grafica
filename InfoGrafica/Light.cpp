#include "Light.h"

Light::Light()
{
	color = glm::vec3(1, 0, 1);
	aIntensity = 1;
}

Light::Light(glm::vec3 color, float ambienteInstensity)
{
	this->color = color;
	this->aIntensity = aIntensity;
}

void Light::UseLight(GLfloat colorLocation, GLfloat aInstesityLocation)
{
	glUniform1f(aInstesityLocation, aIntensity);
	glUniform3f(aInstesityLocation, color.x, color.y, color.z);
}

Light::~Light()
{
}
