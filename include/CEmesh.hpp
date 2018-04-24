
#ifndef CEMESH
#define CEMESH

#include <glew.h> 

#include <CEentity.hpp>
#include <manager/CEresourceMesh.hpp>

class CEMesh : public CEEntity{
public:
	CEMesh(GLuint p_shaderProgram);
	virtual ~CEMesh();

	void loadResource(const char* p_urlSource);

	void beginDraw() override;
	void endDraw() override;

private:
	CEResourceMesh* m_mesh;
	GLuint m_shaderProgram;
};

#endif