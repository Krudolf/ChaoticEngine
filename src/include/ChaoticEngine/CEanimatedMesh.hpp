
#ifndef CEANIMATEDMESH
#define CEANIMATEDMESH

#include <glew.h>

#include "CEentity.hpp"
#include "manager/CEresourceAnimation.hpp"

class CEAnimatedMesh : public CEEntity{
public:
	CEAnimatedMesh(GLuint p_shaderProgram);
	virtual ~CEAnimatedMesh();

	void loadResource(const char* p_urlSource);

	void beginDraw() override;
	void endDraw()   override;

	glm::mat4 getMVP()	{ return m_MVP; }

private:
	std::vector<CEResourceAnimation*> m_animations;
	GLuint m_shaderProgram;

	glm::mat4	m_MVP;
};

#endif