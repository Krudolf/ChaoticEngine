#include <iostream>
#include <../include/CEcamera.hpp>

//Por defecto crea una camara con perspectiva
CECamera::CECamera() : CEEntity(){
	m_isPerspective = true;
	m_proyectionMatrix = glm::perspective(90.0f, 10.f, 0.1f, 100.f);
}

CECamera::~CECamera(){}

void CECamera::setPerspective(float p_angle, float p_aspect, float p_near, float p_far){
	m_isPerspective = true;
	m_angle	 = p_angle;
	m_aspect = p_aspect;
	m_near	 = p_near;
	m_far 	 = p_far;
	m_proyectionMatrix = glm::perspective(m_angle, m_aspect, m_near, m_far);
}

void CECamera::setParallel(float p_left, float p_right, float p_bottom, float p_top, float p_near, float p_far){
	m_isPerspective = false;
	m_left 	 = p_left;
	m_right  = p_right;
	m_bottom = p_bottom;
	m_top 	 = p_top;
	m_near	 = p_near;
	m_far 	 = p_far;
	m_proyectionMatrix = glm::ortho(m_left, m_right, m_bottom, m_top, m_near, m_far);
}

glm::mat4 CECamera::getMatrix(){
	return m_proyectionMatrix;
}


void CECamera::beginDraw(){}

void CECamera::endDraw(){}
