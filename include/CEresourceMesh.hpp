 
#ifndef CERESOURMESH
#define CERESOURMESH

#include <vector>

#include <glew.h>
#include <glut.h>

#include <glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
	CEResourceMesh(std::vector<Vertex> p_vertices, std::vector<GLuint> p_indices);
	~CEResourceMesh();

	bool loadFile(const char* p_name);
	void draw();

private:
	std::vector<CEResourceMesh*> m_meshes;

	/*  Mesh Data  */
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	long int m_nTriangles;

	/*  Render data  */
	GLuint m_VAO = 0;
	GLuint m_VBO = 0;
	GLuint m_EBO = 0;
	
	void 			prepareBuffers();
	void 			processNode(aiNode* p_node, const aiScene* p_scene);
	CEResourceMesh* processMesh(aiMesh* p_mesh, const aiScene* p_scene);

};

#endif