#ifndef CESUBMESH
#define CESUBMESH

#include <GL/glew.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
	// Position of vertices from the mesh
	glm::vec3 Position;
	// Normals
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};


class CEsubMesh
{

public:
	/*  Mesh Data  */
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;

	CEsubMesh(std::vector<Vertex> p_vertices, std::vector<GLuint> p_indices);
	~CEsubMesh();

	void subDraw();

private:
	/*  Render data  */
	GLuint m_VAO = 0;
	GLuint m_VBO = 0;
	GLuint m_EBO = 0;

	void prepareBuffers();
};

#endif