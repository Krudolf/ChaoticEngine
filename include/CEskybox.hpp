
#ifndef CESKYBOX
#define CESKYBOX

#include <glew.h> 
#include <glm.hpp>
#include <CEentity.hpp>
#include <CEresourceTexture.hpp>

class CESkybox : public CEEntity{
public:
	CESkybox();
	virtual ~CESkybox();

	unsigned int loadCubemap(const char* p_texturesPath[6]);//0->right, 1->left, 2->top, 3->bottom, 4->front, 5->back
	void beginDraw() override;
	void endDraw() override;

private:

	CEResourceTexture* m_texturesFaces[6]; //0->right, 1->left, 2->top, 3->bottom, 4->front, 5->back
	unsigned int m_skyboxVAO, m_skyboxVBO;
};

#endif