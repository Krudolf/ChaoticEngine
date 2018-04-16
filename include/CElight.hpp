#ifndef CELIGHT
#define CELIGHT

#include <glm.hpp>
#include <glew.h> 
#include <CEentity.hpp>

class CELight : public CEEntity{
public:
	CELight(glm::vec3 m_intensities, float m_attenuation);
	virtual ~CELight();

	void setIntensities(glm::vec3 p_intensities);
	void setAtenuation(float p_attenuation);
	void setShader(GLuint p_shaderProgram){ m_shaderProgram = p_shaderProgram;}

	void beginDraw() override;
	void endDraw() override;

private:
    glm::vec3 m_intensities; //(0-1)red, green and blue intensities 
    GLuint m_shaderProgram;
    float m_attenuation;
};

#endif