
#include <iostream>
#include <glm.hpp>

#include "../../include/fachada/CEScene.hpp"
#include "../../include/fachada/CESceneCamera.hpp"
#include "../../include/fachada/CESceneLight.hpp"
#include "../../include/fachada/CESceneMesh.hpp"
#include "../../include/fachada/CEShader.hpp"
#include "../../include/CEemitter.hpp"
#include "../../include/CEtransform.hpp"

CEScene::CEScene(){
	m_root = new CESceneNode();
	
	CETransform* rootEntity = new CETransform();
	m_root->setEntity(rootEntity);

	m_resourceManager = new CEResourceManager();

	m_shaderProgram = new CEShaderProgram("shader/CEVertexPhong.vert", "shader/CEFragmentPhong.frag");
	m_shaderProgram->loadShader("shader/CEVertexSkybox.vert", "shader/CEFragmentSkybox.frag");
	m_shaderProgram->loadShader("shader/CEVertexParticle.vert", "shader/CEFragmentParticle.frag");
}

CEScene::~CEScene(){
	delete m_root;
	m_root = nullptr;

	delete m_resourceManager;
	m_resourceManager = nullptr;

	delete m_shaderProgram;
	m_shaderProgram = nullptr;
}

CESceneCamera* CEScene::createCamera(bool p_isActive){
	CESceneCamera* CEcamera = new CESceneCamera(m_root, p_isActive);
	m_cameras.push_back(CEcamera);

	if(p_isActive){
		m_activeCamera = CEcamera;
		m_activeCamera->activateCamera();
	}

	return CEcamera;
}

CESceneLight* CEScene::createLight(){
	glm::vec3 	intensities = glm::vec3(1, 1, 1);
	float 		attenuation = 0.0f;

	CESceneLight* CElight = new CESceneLight(m_root, intensities, attenuation, m_shaderProgram->getShaderProgram(0));
	m_lights.push_back(CElight);

	return CElight;	
}

CESceneMesh* CEScene::createMesh(const char* p_path){
	CESceneMesh* CEmesh = new CESceneMesh(m_root, p_path, m_shaderProgram->getShaderProgram(0));

	return CEmesh;	
}

CESkybox* CEScene::createSkybox(const char* p_texturesPath[6]){
	CESkybox* CEsky = new CESkybox();
	CEsky->loadCubemap(p_texturesPath);

	return	CEsky;
}

CEEmitter* CEScene::createEmitter()
{
	std::cout << "CREAMOS" << std::endl;
	CETransform*	m_rotate    = new CETransform();
	CETransform* m_scale	    = new CETransform();
	CETransform* m_translate = new CETransform(); 
	CEEmitter* emitter = new CEEmitter(m_shaderProgram->getShaderProgram(2));
	
	m_rotate->rotate(0, 0, 0);
	m_scale->scale(1, 1, 1);
	m_translate->translate(0, 0, 0);

	CESceneNode* t_nodeRotate 	 = new CESceneNode(m_root);
	CESceneNode* t_nodeScale 	 = new CESceneNode(t_nodeRotate);
	CESceneNode* t_nodeTranslate = new CESceneNode(t_nodeScale);
	CESceneNode* t_nodeEmitter 	 = new CESceneNode(t_nodeTranslate);
	t_nodeRotate->setEntity(m_rotate);
	t_nodeScale->setEntity(m_scale);
	t_nodeTranslate->setEntity(m_translate);
	t_nodeEmitter->setEntity(emitter);
	//m_shaderProgram

	return emitter;
}

void CEScene::setActiveCamera(CESceneCamera* p_camera){
	m_activeCamera = p_camera;
	m_activeCamera->activateCamera();
}

void CEScene::draw(){
	m_root->draw();
}

void CEScene::release(){
	m_root->removeAllChilds();
	m_resourceManager->deleteResources();

	delete m_resourceManager;
	delete m_root;
}