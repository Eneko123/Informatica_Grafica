#include "Light.h"

Light::Light()
{
	direction = glm::vec3(0.0f, 0.0f, 0.0f);
	color = glm::vec3(1.0f, 0.0f, 1.0f);
	aInstensity = 0.0f;
	dIntensity = 0.0f;
}

Light::Light(glm::vec3 directio, glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity)
{
	this->direction = directio;
	this->color = color;
	this->aInstensity = ambientIntensity;
	this->dIntensity = diffuseIntensity;
}

void Light::UseLight(GLfloat colorLocation, GLfloat aIntensityLocation, GLfloat directionLocation, GLfloat dIntensityLocation)
{
	glUniform1f(aIntensityLocation, aInstensity);
	glUniform1f(dIntensityLocation, dIntensity);
	glUniform3f(colorLocation, color.x, color.y, color.z);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
}

Light::~Light()
{
}
