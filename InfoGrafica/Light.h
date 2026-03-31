#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class Light
{
public:
	Light();
	Light(glm::vec3 directio ,glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity);
	void UseLight(GLfloat colorLocation, GLfloat aIntensityLocation, GLfloat directionLocation, GLfloat dIntensity);
	~Light();
private:
	glm::vec3 direction;
	glm::vec3 color;
	GLfloat aInstensity;
	GLfloat dIntensity;

};

