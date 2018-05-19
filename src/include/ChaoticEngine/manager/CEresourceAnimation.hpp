 
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
	void draw(GLuint p_shaderProgram, int p_frame);
	int  getNumFrames(){ return m_meshes.size(); }
	bool getLoopable(){ return m_loop; }
	void setLoopable(bool p_loopable){ m_loop = p_loopable; }

private:
	std::vector<CEResourceMesh*> m_meshes;
	bool m_loop = 0;
    void meshList();
};

#endif