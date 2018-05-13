#ifndef CELIGHT
#define CELIGHT

#include <glew.h>

#include "CEentity.hpp"

class CELight : public CEEntity{
public:
	CELight(glm::vec3 m_intensities, float m_attenuation, GLuint p_shaderProgram);
	virtual ~CELight();

	void setIntensities(glm::vec3 p_intensities);
	void setAtenuation(float p_attenuation);

	void beginDraw() override;
	void endDraw() override;

	glm::mat4 	getMVP()		{ return m_MVP; }

	glm::vec3 	getAmbient()	{ return m_ambient;		}
	glm::vec3 	getDiffuse()	{ return m_diffuse;		}
	glm::vec3 	getSpecular()	{ return m_specular;	}

	float		getLinear()		{ return m_linear;		}
	float		getConstant()	{ return m_constant;	}
	float		getQuadratic()	{ return m_quadratic;	}

private:
    GLuint 		m_shaderProgram;
    glm::vec3 	m_intensities; //(0-1)red, green and blue intensities 
	glm::mat4	m_MVP;

	glm::vec3	m_ambient;
	glm::vec3	m_diffuse;
	glm::vec3	m_specular;
    
    float		m_linear;
    float 		m_constant;
    float 		m_quadratic;

    float 		m_attenuation;
};

#endif