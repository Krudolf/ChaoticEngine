 
#ifndef CERESOURMESH
#define CERESOURMESH

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "manager/CEresource.hpp"
#include "CEsubMesh.hpp"


class CEResourceMesh: public CEResource{
public:
	CEResourceMesh();
	~CEResourceMesh();

	bool loadFile(const char* p_name);
	void draw(glm::mat4 p_modelMatrix);

private:
	std::vector<CEsubMesh> m_meshes;
	
	void processNode(aiNode* p_node, const aiScene* p_scene);
	CEsubMesh processMesh(aiMesh* p_mesh, const aiScene* p_scene);

};

#endif