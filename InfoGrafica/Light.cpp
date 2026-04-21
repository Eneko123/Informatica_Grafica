#include "Light.h"

Light::Light()
{
	color = glm::vec3(1.0f, 0.0f, 1.0f);
	aInstensity = 0.0f;
	dIntensity = 0.0f;

}

Light::Light(glm::vec3 color, GLfloat ambientIntensity, glm::vec3 dir, GLfloat diffuseIntensity)
{
	this->color = color;
	this->aInstensity = ambientIntensity;
	dIntensity = diffuseIntensity;
}

Light::~Light()
{
}

void Light::UseLight(UniformBaseLight baseLigth)
{
	glUniform1f(baseLigth.uniformAmbientInten, aInstensity);
	glUniform1f(baseLigth.uniformDiffuseInten, dIntensity);
	glUniform3f(baseLigth.uniformColor, color.x, color.y, color.z);
}
