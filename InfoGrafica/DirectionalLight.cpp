#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
{
}

DirectionalLight::DirectionalLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, glm::vec3 dir)
	: Light(color, ambientIntensity, dir, diffuseIntensity)
{
	direction = dir;
}

void DirectionalLight::UseLight(UniformDirectionalLight uniformDirectionalLight)
{
	Light::UseLight(uniformDirectionalLight);
	glUniform3f(uniformDirectionalLight.uniformDir, direction.x, direction.y, direction.z);
}
