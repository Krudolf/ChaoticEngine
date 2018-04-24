
#include <iostream>
#include <gtc/matrix_transform.hpp> //For glm transformations

#include <../../include/fachada/CESceneCamera.hpp>

CESceneCamera::CESceneCamera(CESceneNode* p_parent, bool p_isActive){
	m_isActive = p_isActive;

	m_rotate    = new CETransform();
	m_translate = new CETransform(); 
	m_camera 	= new CECamera();
	
	m_rotate->rotate(0, 0, 0);
	m_translate->translate(0, 0, -2.0f);

	CESceneNode* t_nodeRotate 	 = new CESceneNode(p_parent);
	CESceneNode* t_nodeTranslate = new CESceneNode(t_nodeRotate);
	CESceneNode* t_nodeCamera 	 = new CESceneNode(t_nodeTranslate);
	t_nodeRotate->setEntity(m_rotate);
	t_nodeTranslate->setEntity(m_translate);
	t_nodeCamera->setEntity(m_camera);
}

CESceneCamera::~CESceneCamera(){}

void CESceneCamera::activateCamera(){
	m_camera->setProjectionMatrix();
	m_camera->setViewMatrix(this->getViewMatrix());
}

glm::mat4 CESceneCamera::getViewMatrix(){
	glm::mat4 m_tempMatrix;

	m_tempMatrix = m_rotate->getMatrix() * m_translate->getMatrix();
	m_tempMatrix = glm::inverse(m_tempMatrix);

	return m_tempMatrix;
}
