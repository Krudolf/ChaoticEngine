 
#ifndef CERESOURMESH
#define CERESOURMESH

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <string>
#include "stb_image.h"

#include "manager/CEresource.hpp"
#include "CEsubMesh.hpp"

GLint TextureFromFile(const char* p_path, std::string p_directory);

class CEResourceMesh: public CEResource{
public:
	CEResourceMesh();
	~CEResourceMesh();

	bool loadFile(const char* p_name);
	void draw(glm::mat4 p_modelMatrix, GLuint p_shaderProgram);

private:
	std::vector<CEsubMesh> m_meshes;
	std::vector<Texture> m_textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    std::string m_directory;
	
	void processNode(aiNode* p_node, const aiScene* p_scene);
	CEsubMesh processMesh(aiMesh* p_mesh, const aiScene* p_scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* p_mat, aiTextureType p_type, std::string p_typeName);

};

#endif