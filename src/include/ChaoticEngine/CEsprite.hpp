
#ifndef CESPRITE
#define CESPRITE

#include <glew.h>

#include "CEentity.hpp"
#include "manager/CEresourceTexture.hpp"

class CESprite : public CEEntity{
public:
	CESprite(const char* p_urlSource, float p_width, float p_height, GLuint p_shaderProgram);
	virtual ~CESprite();

	void 	loadResource(const char* p_urlSource);

	void 	beginDraw() override;
	void 	endDraw()   override;

	glm::mat4 getMVP()	{ return m_MVP; }


	float 	getWidth() 				    {	return m_width;			}
	float 	getHeight() 				{	return m_height;		}
	void 	setWidth(float p_width)	    {	m_width  = p_width;		}
	void 	setHeight(float p_height)	{	m_height = p_height;	}

	void	getNext();
	void	getLast();

private:
	GLuint m_shaderProgram;
    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_EBO;

    glm::mat4 m_MVP;

    std::vector<CEResourceTexture*> m_texture;
    int	  m_currentFrame;
    int	  m_totalFrames;

    float m_width;
	float m_height;
};

#endif