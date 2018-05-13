 
#ifndef CERESOURCEANIMATION
#define CERESOURCEANIMATION

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "CEresource.hpp"
#include "CEresourceMesh.hpp"

class CEResourceAnimation: public CEResource{
public:
	CEResourceAnimation();
	~CEResourceAnimation();

	bool loadFile(const char* p_name);
	void draw(GLuint p_shaderProgram);

private:
	std::vector<CEResourceMesh*> m_meshes;
    std::string m_directory;
};

#endif