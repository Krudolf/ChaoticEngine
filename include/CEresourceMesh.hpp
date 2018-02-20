 
#ifndef CERESOURMESH
#define CERESOURMESH

#include <vector>
#include <glm.hpp>
#include <GL/glew.h> 
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "manager/CEresource.hpp"

struct Vertex {
	// Position of vertices from the mesh
	glm::vec3 Position;
	// Normals
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};


class CEResourceMesh: public CEResource{
public:
	CEResourceMesh();
	~CEResourceMesh();

	void loadFile(const char* p_name);
	void draw();

private:
	/*  Mesh Data  */
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	long int m_nTriangles;
	/*  Render data  */
	GLuint VAO, VBO, EBO;
	
	void processNode(aiNode* p_node, const aiScene* p_scene);
	void processMesh(aiMesh* p_mesh, const aiScene* p_scene);
	void prepareBuffers();

};

#endif