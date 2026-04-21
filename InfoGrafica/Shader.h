#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <glm/glm.hpp>

struct UniformBaseLight {
	GLuint uniformColor;
	GLuint uniformAmbientInten;
	GLuint uniformDiffuseInten;
	
};
struct UniformDirectionalLight : public UniformBaseLight {
	GLuint uniformDir;
};
struct UniformPointLight : public UniformBaseLight {
	GLuint uniformPosition;
	GLuint uniformConstant;
	GLuint uniformLinear;
	GLuint uniformExponential;
};
struct UniformSpotLight : public UniformBaseLight {
	GLuint uniformPosition;
};

class Shader
{
public:
	Shader();
	void CreateShadersFromString(const char* vertexCode, const char* fragmentCode);
	void CreateShadersFromFile(const char* vertexPath, const char* fragmentPath);

	GLuint GetIdModel() { return uniformModel; }
	GLuint GetIdProjection() { return uniformProjection; }
	GLuint GetIdView() { return uniformView; }
	GLuint GetIdCameraPos() { return uniformCameraPos; }
	const UniformDirectionalLight GetIdDirectionalLight() const { return uniformDirectionalLight; }
	const UniformPointLight GetIdPointLight() const { return uniformPointLight; }
	GLuint GetIdShininess() { return uniformShininess; }
	GLuint GetIdSpecularInten() { return uniformSpecularInten; }
	GLuint GetIdTime() { return uniformTime; }



	void useShader();
	void deleteShader();
	~Shader();


private:
	GLuint idShader = 0, uniformModel = 0, uniformProjection = 0, uniformView = 0, uniformCameraPos = 0;
	GLuint uniformShininess, uniformSpecularInten;
	GLuint uniformTime = 0;

	UniformDirectionalLight uniformDirectionalLight;
	UniformPointLight uniformPointLight;

	std::string ReadFile(const char* path);
	void AddShader(const char* shaderCode, GLenum shaderType);
	void CompileShader(const char* vertexCode, const char* fragmentCode);


};

