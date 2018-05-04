
#ifndef CEMESH
#define CEMESH

#include <glew.h>

#include "CEentity.hpp"
#include "manager/CEresourceMesh.hpp"

class CEEmitter : public CEEntity{
public:
	CEEmitter(GLuint p_shaderProgram);
	virtual ~CEEmitter();

	void loadResource(const char* p_urlSource);

	void beginDraw() override;
	void endDraw()   override;

	glm::mat4	getModelMatrix()	{ return m_modelMatrix;	};

private:
	CEResourceMesh* m_emitter;
	GLuint m_shaderProgram;
};

#endif