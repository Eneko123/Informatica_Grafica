#include "Material.h"

Material::Material()
{
	specularIntensity = 0.0f;
	shininess = 1.0f;
}

Material::Material(GLfloat specularIntensity, GLfloat shininess)
{
	this->specularIntensity = specularIntensity;
	this->shininess = shininess;
}

void Material::UseMaterial(GLfloat specularIntensityLocation, GLfloat shininessLocation)
{
	glUniform1f(specularIntensityLocation, specularIntensity);
	glUniform1f(shininessLocation, shininess);
}

Material::~Material()
{
}
