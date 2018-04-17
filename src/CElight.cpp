#include <iostream>
#include <../include/CElight.hpp>
#include <gtc/type_ptr.hpp>

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

void CELight::beginDraw(){

	glm::vec3 l_pos = glm::vec3(1, 0, 0);
    glUniform3fv(glGetUniformLocation(m_shaderProgram, "Light.Position"), 1, glm::value_ptr(l_pos));

    glUniform3fv(glGetUniformLocation(m_shaderProgram, "Light.Ambient"), 1, glm::value_ptr(m_intensities));
    glUniform3fv(glGetUniformLocation(m_shaderProgram, "Light.Diffuse"), 1, glm::value_ptr(m_intensities));
    glUniform3fv(glGetUniformLocation(m_shaderProgram, "Light.Specular"), 1, glm::value_ptr(m_intensities));
}

void CELight::endDraw(){}