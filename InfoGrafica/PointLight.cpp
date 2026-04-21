#include "PointLight.h"

PointLight::PointLight() : Light()
{
    pos = glm::vec3(0.0f, 0.0f, 0.0f);
    constantValue = 1.0f;
    linealValue = 0.0f;
	exponentialValue = 0.0f;
}

PointLight::PointLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, glm::vec3 pos, float constant, float linear, float exponential)
    : Light(color, ambientIntensity, pos, diffuseIntensity)
{
    this->pos = pos;
    this->constantValue = constant;
    this->linealValue = linear;
    this->exponentialValue = exponential;
}

void PointLight::UseLight(UniformPointLight uniformPointLight)
{
    Light::UseLight(uniformPointLight);
	glUniform3f(uniformPointLight.uniformPosition, pos.x, pos.y, pos.z);
	glUniform1f(uniformPointLight.uniformConstant, constantValue);
	glUniform1f(uniformPointLight.uniformLinear, linealValue);
	glUniform1f(uniformPointLight.uniformExponential, exponentialValue);
}
