
#include <gtc/type_ptr.hpp>

#include "../include/ChaoticEngine/CElight.hpp"

CELight::CELight(glm::vec3 p_intensities, float p_attenuation, GLuint p_shaderProgram) : CEEntity(){
	m_intensities 	= p_intensities;
	m_attenuation 	= p_attenuation;
	m_shaderProgram = p_shaderProgram;

	m_ambient	= glm::vec3(0.1f, 0.1f, 0.1f);
	m_diffuse	= glm::vec3(0.8f, 0.8f, 0.8f);
	m_specular	= glm::vec3(1.0f, 1.0f, 1.0f);

	m_linear	= 1.0;
    m_constant	= 0.045;
    m_quadratic	= 0.0075;
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

void CELight::beginDraw(){
	m_MVP = m_projectionMatrix * m_viewMatrix * m_modelMatrix;
}

void CELight::endDraw(){}