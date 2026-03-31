#pragma once
#include <GL/glew.h>

class Material
{
public:
	Material();
	Material(GLfloat specularIntensity, GLfloat shininess);
	void UseMaterial(GLfloat specularIntensityLocation, GLfloat shininessLocation);
	// GLfloat GetAmbientIntensity() { return ambientIntensity; }
	// GLfloat GetDiffuseIntensity() { return diffuseIntensity; }
	GLfloat GetSpecularIntensity() { return specularIntensity; }
	GLfloat GetShininess() { return shininess; }
	~Material();
private:
	// GLfloat ambientIntensity;
	// GLfloat diffuseIntensity;
	GLfloat specularIntensity;
	GLfloat shininess;
};

