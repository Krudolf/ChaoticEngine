#include <iostream>
#include <../include/CElight.hpp>

CELight::CELight(glm::vec3 p_position) : CEEntity(){
	m_position = p_position;
}

CELight::~CELight(){}

void CELight::beginDraw(){
	std::cout<<"Dibujamos luz en la posicion" << m_position.x <<", "<< m_position.y <<", "<< m_position.z << std::endl;
}

void CELight::endDraw(){}