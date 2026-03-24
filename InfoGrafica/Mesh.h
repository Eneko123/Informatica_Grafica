#pragma once

#include <GL/glew.h>

class Mesh
{
public:
	Mesh();
	void CreateMesh(GLfloat* vertices, GLuint* indices, GLuint numVertices, GLsizei numIndices);
	void DeleteMesh();
	void RenderMesh();
	void RecalculateNormals(GLfloat* vertices, GLuint* indices, GLuint numVertices, GLsizei numIndices, unsigned int numDatosV, unsigned int offsetNormal);
	~Mesh();
private:
	GLuint VAO = 0, VBO = 0, EBO = 0;
	GLsizei indexCount = 0;
};

