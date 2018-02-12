#ifndef CELIGHT
#define CELIGHT

#include <glm.hpp>
#include <CEentity.hpp>

class CELight : public CEEntity{
public:
	CELight(glm::vec3 m_position, glm::vec3 m_intensities);
	~CELight();

	void beginDraw();
	void endDraw();
	void setPosition(glm::vec3 p_position);
	void setIntensities(glm::vec3 p_intensities);

private:
	glm::vec3 m_position;
    glm::vec3 m_intensities; //(0-1)red, green and blue intensities 
    float attenuation;
};

#endif