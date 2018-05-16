
#ifndef CE_SCENE_SPRITE
#define CE_SCENE_SPRITE

#include <glew.h>
#include <glfw3.h>

#include "../CEsprite.hpp"
#include "../CEtransform.hpp"
#include "../CEscenenode.hpp"

class CESceneSprite{
public:
	CESceneSprite(CESceneNode* p_parent, const char* p_path, float p_width, float p_height, GLuint p_shaderProgram);
	~CESceneSprite();

	void 	processInput(GLFWwindow* p_window);

	void 	setScale(float p_x, float p_y, float p_z);
	void 	setRotation(float p_x, float p_y, float p_z);
	void 	setPosition(float p_x, float p_y, float p_z);

	void 	setAbsoluteScale(float p_x, float p_y, float p_z);
	void 	setAbsoluteRotation(float p_x, float p_y, float p_z);
	void 	setAbsolutePosition(float p_x, float p_y, float p_z);

    glm::vec3	getPosition() { return glm::vec3(glm::inverse(m_sprite->getMVP())[3]); }    

	float 	getHeight() 				{   return m_sprite->getHeight();   }
	float 	getWidth() 				    {	return m_sprite->getWidth();    }
   	void 	setWidth(float p_width)	    {	m_sprite->setWidth(p_width);    }
	void 	setHeight(float p_height)	{   m_sprite->setHeight(p_height);  }

	void 	addTexture(const char* p_urlSource) { m_sprite->loadResource(p_urlSource); }

private:
	CESprite*		m_sprite;
	CETransform*	m_rotate;
	CETransform*	m_scale;
	CETransform*	m_translate;

};

#endif
