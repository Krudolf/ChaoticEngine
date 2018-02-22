#ifndef CECAMERA
#define CECAMERA

#include <glm.hpp>
#include <gtc/matrix_transform.hpp> //For glm transformations

#include <CEentity.hpp>

class CECamera : public CEEntity{
public:
	CECamera();
	~CECamera();

	void setPerspective(float p_angle, float p_aspect, float p_near = 0.1f, float p_far = 100.0f);
	void setParallel(float p_left, float p_right, float p_bottom, float p_top, float p_near = 0.1f, float p_far = 100.0f);

	void beginDraw();
	void endDraw();

	/*Preguntar por el lookAt() de GLM*/

private:
	glm::mat4 m_proyectionMatrix;

    bool m_isPerspective;
    
    float m_near, m_far;
    float m_angle, m_aspect;
    float m_left, m_right, m_bottom, m_top;
};

#endif