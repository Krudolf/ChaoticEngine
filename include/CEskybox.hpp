
#ifndef CESKYBOX
#define CESKYBOX

#include <glew.h> 
#include <glm.hpp>
#include "CEentity.hpp"
#include "manager/CEresourceTexture.hpp"

class CESkybox : public CEEntity{
public:
	CESkybox(GLuint p_shaderProgram);
	virtual ~CESkybox();

	void loadCubemap(const char* p_texturesPath[6]);//0->right, 1->left, 2->top, 3->bottom, 4->front, 5->back
	void beginDraw() override;
	void endDraw() override;

private:

	CEResourceTexture* m_texturesFaces[6]; //0->right, 1->left, 2->top, 3->bottom, 4->front, 5->back
	unsigned int m_skyboxVAO, m_skyboxVBO;
	GLuint m_shaderProgram;
	unsigned int m_textureID;
};

#endif