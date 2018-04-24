
#include <iostream>

#include <../../include/fachada/CESceneLight.hpp>

CESceneLight::CESceneLight(CESceneNode* p_parent, glm::vec3 p_intensities, float p_attenuation, GLuint p_shaderProgram, bool p_isActive){
	m_intensities = p_intensities;
	m_attenuation = p_attenuation;
	m_isActive	  = p_isActive;

	m_rotate    = new CETransform();
	m_translate = new CETransform();
	m_light 	= new CELight(p_intensities, p_attenuation, p_shaderProgram);
	
	m_rotate->rotate(0, 0, 0);
	m_translate->translate(0, 0, 0);

	CESceneNode* t_nodeRotate 	 = new CESceneNode(p_parent);
	CESceneNode* t_nodeTranslate = new CESceneNode(t_nodeRotate);
	CESceneNode* t_nodeLight 	 = new CESceneNode(t_nodeTranslate);
	t_nodeRotate->setEntity(m_rotate);
	t_nodeTranslate->setEntity(m_translate);
	t_nodeLight->setEntity(m_light);
}

CESceneLight::~CESceneLight(){}

