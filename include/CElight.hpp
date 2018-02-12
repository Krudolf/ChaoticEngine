#ifndef CELIGHT
#define CELIGHT

#include <glm.hpp>
#include <CEentity.hpp>

class CELight : public CEEntity{
public:
	CELight(glm::vec3 m_position);
	~CELight();

	void beginDraw();
	void endDraw();

private:
	glm::vec3 m_position;
    glm::vec3 m_intensities; //(0-1)red, green and blue intensities 
};

#endif