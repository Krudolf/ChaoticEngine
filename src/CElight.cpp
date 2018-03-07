#include <iostream>
#include <../include/CElight.hpp>

CELight::CELight(glm::vec3 p_intensities, float p_attenuation) : CEEntity(){
	m_intensities = p_intensities;
	m_attenuation = p_attenuation;
}

CELight::~CELight(){}

void CELight::setIntensities(glm::vec3 p_intensities){
	m_intensities.x = p_intensities.x;
	m_intensities.y = p_intensities.y;
	m_intensities.z = p_intensities.z;
}

void CELight::setAtenuation(float p_attenuation){
	m_attenuation = p_attenuation;
}

void CELight::beginDraw(){}

void CELight::endDraw(){}