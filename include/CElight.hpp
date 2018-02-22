#ifndef CELIGHT
#define CELIGHT

#include <glm.hpp>
#include <CEentity.hpp>

class CELight : public CEEntity{
public:
	CELight(glm::vec3 m_intensities, float m_attenuation);
	~CELight();

	void setIntensities(glm::vec3 p_intensities);
	void setAtenuation(float p_attenuation);

	void beginDraw();
	void endDraw();

private:
    glm::vec3 m_intensities; //(0-1)red, green and blue intensities 
    
    float m_attenuation;
};

#endif