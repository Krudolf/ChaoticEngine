#include <iostream>
#include <../include/CElight.hpp>

CELight::CELight(glm::vec3 p_position, glm::vec3 p_intensities) : CEEntity(){
	m_position = p_position;
	m_intensities = p_intensities;
}

CELight::~CELight(){}

void CELight::beginDraw(){
	std::cout<<"Dibujamos luz en la posicion" <<", "<< m_position.x <<", "<< m_position.y <<", "<< m_position.z << std::endl;
	std::cout<<"Intensidad de la luz" <<", "<< m_intensities.x <<", "<< m_intensities.y <<", "<< m_intensities.z << std::endl;
	setPosition(glm::vec3(200, 5, 89));
	std::cout<<"Dibujamos luz en la posicion" <<", "<< m_position.x <<", "<< m_position.y <<", "<< m_position.z << std::endl;
}

void CELight::endDraw(){}

void CELight::setIntensities(glm::vec3 p_intensities){
	m_intensities.x = p_intensities.x;
	m_intensities.y = p_intensities.y;
	m_intensities.z = p_intensities.z;
}

void CELight::setPosition(glm::vec3 p_position){
	m_position.x = p_position.x;
	m_position.y = p_position.y;
	m_position.z = p_position.z;
}