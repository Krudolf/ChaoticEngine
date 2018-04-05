#ifndef CESUBMESH
#define CESUBMESH

#include <glew.h> 
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

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
	// tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

struct Texture {
    GLuint id;
    std::string type;
    std::string path;
}; 

class CEsubMesh
{

public:
	/*  Mesh Data  */
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	std::vector<Texture> m_textures;

	CEsubMesh(std::vector<Vertex> p_vertices, std::vector<GLuint> p_indices, std::vector<Texture> p_textures);
	~CEsubMesh();

	void subDraw(glm::mat4 p_modelMatrix, GLuint p_shaderProgram);

private:
	/*  Render data  */
	GLuint m_VAO = 0;
	GLuint m_VBO = 0;
	GLuint m_EBO = 0;

	void prepareBuffers();
};

#endif