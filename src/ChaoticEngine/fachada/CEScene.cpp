
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <glm.hpp>

#include "../../include/ChaoticEngine/fachada/CEScene.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneCamera.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneLight.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneMesh.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneAnimation.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneQuad.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneSprite.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneParticleSystem.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneSkybox.hpp"
#include "../../include/ChaoticEngine/fachada/CESceneBillboard.hpp"
#include "../../include/ChaoticEngine/fachada/CEShader.hpp"
#include "../../include/ChaoticEngine/CEtransform.hpp"

CEScene::CEScene(){
	m_root = new CESceneNode();
	
	CETransform* rootEntity = new CETransform();
	m_root->setEntity(rootEntity);

	m_resourceManager = new CEResourceManager();

	//[ 0 ] - Main shader
	m_shaderProgram = new CEShaderProgram("src/ChaoticEngine/shader/CEvertex.vert", "src/ChaoticEngine/shader/CEfragment.frag");
	//[ 1 ] - Shader for the debug quads
	m_shaderProgram->loadShader("src/ChaoticEngine/shader/CEvertQuad.vert", "src/ChaoticEngine/shader/CEfragQuad.frag");
	//[ 2 ] - Shader for the sprites
	m_shaderProgram->loadShader("src/ChaoticEngine/shader/CEvertSprite.vert", "src/ChaoticEngine/shader/CEfragSprite.frag");
	//[ 3 ] - Shader for the particle system
	m_shaderProgram->loadShader("src/ChaoticEngine/shader/CEvertParticle.vert", "src/ChaoticEngine/shader/CEfragParticle.frag");
	//[ 4 ] - Shader for the skybox
	m_shaderProgram->loadShader("src/ChaoticEngine/shader/CEvertSkybox.vert", "src/ChaoticEngine/shader/CEfragSkybox.frag");
	
	//[ 5 ] - Shader for the cartoon
	m_shaderProgram->loadShader("src/ChaoticEngine/shader/CEvertex.vert", "src/ChaoticEngine/shader/CEfragCartoon.frag");
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
	CEcamera->setPosition(0,2,5);

	m_cameras.push_back(CEcamera);

	if(p_isActive){
		m_activeCamera = CEcamera;
		m_activeCamera->activateCamera();
	}

	return CEcamera;
}

CESceneLight* CEScene::createDirectionalLight(float p_direction[3], float p_position[3]){
	glm::vec3 t_direction(p_direction[0], p_direction[1], p_direction[2]);

	m_directionalLight = new CESceneLight(m_root, t_direction, m_shaderProgram->getShaderProgram(0));
	m_directionalLight->setPosition(p_position[0], p_position[1], p_position[2]);

	return m_directionalLight;
}

CESceneLight* CEScene::createPointLight(float p_lightAtenuation, float p_position[3]){
	float 		t_attenuation = p_lightAtenuation;

	CESceneLight* CElight = new CESceneLight(m_root, t_attenuation, m_shaderProgram->getShaderProgram(0));
	CElight->setPosition(p_position[0], p_position[1], p_position[2]);
	
	m_lights.push_back(CElight);

	return CElight;	
}

CESceneMesh* CEScene::createMesh(const char* p_path){
	CESceneMesh* CEmesh = new CESceneMesh(m_root, p_path, m_shaderProgram->getShaderProgram(5));

	return CEmesh;	
}

CESceneAnimation* CEScene::createAnimatedMesh(const char* p_path){
	CESceneAnimation* CEanimMesh = new CESceneAnimation(m_root, p_path, m_shaderProgram->getShaderProgram(5));

	return CEanimMesh;	
}

CESceneQuad* CEScene::createQuad(float p_vertex[4][2]){
	CESceneQuad* CEquad = new CESceneQuad(m_root, p_vertex, m_shaderProgram->getShaderProgram(1));

	return CEquad;	
}

CESceneSprite* CEScene::createSprite(const char* p_path, float p_width, float p_height){
	CESceneSprite* CEsprite = new CESceneSprite(m_root, p_path, p_width, p_height, m_shaderProgram->getShaderProgram(2));

	return CEsprite;
}

CESceneBillboard* CEScene::createBillboard(const char* p_path, float p_width, float p_height, CESceneNode* p_parent){
	CESceneBillboard* CEbillboard;
	if(p_parent == NULL)
		CEbillboard = new CESceneBillboard(m_root, p_path, p_width, p_height, m_shaderProgram->getShaderProgram(2));
	else
		CEbillboard = new CESceneBillboard(p_parent, p_path, p_width, p_height, m_shaderProgram->getShaderProgram(2));

	return CEbillboard;
}

CESceneParticleSystem* CEScene::createParticleSystem(const char* p_path, int p_amount){
	CESceneParticleSystem* CEemitter = new CESceneParticleSystem(m_root, p_path, p_amount, m_shaderProgram->getShaderProgram(3));

	return CEemitter;
}

CESceneSkybox* CEScene::createSkybox(const char* p_path[6], float p_scale){
	CESceneSkybox* CEskybox = new CESceneSkybox(m_root, p_path, p_scale, m_shaderProgram->getShaderProgram(4));

	return CEskybox;
}

void CEScene::setActiveCamera(CESceneCamera* p_camera){
	m_activeCamera = p_camera;
	m_activeCamera->activateCamera();
}

void CEScene::calculateLights(){
	GLuint t_shaderProgram = m_shaderProgram->getShaderProgram(0);
	glUseProgram(m_shaderProgram->getShaderProgram(0));

	std::string t_light		= "Light[";
	std::string t_position	= "].Position";
	std::string t_ambient	= "].Ambient";
	std::string t_diffuse	= "].Diffuse";
	std::string t_specular	= "].Specular";
	std::string t_atten		= "].Attenuation";
	std::string t_result;

	glUniform3fv(glGetUniformLocation(t_shaderProgram, "viewPos"), 1, glm::value_ptr(m_activeCamera->getPosition()));
	glUniform3fv(glGetUniformLocation(t_shaderProgram, "lightPos"), 1, glm::value_ptr(m_directionalLight->getPosition()));

	glUniform3fv(glGetUniformLocation(t_shaderProgram, "DirLight.Direction"), 1, glm::value_ptr(m_directionalLight->getDirection()));
	glUniform3fv(glGetUniformLocation(t_shaderProgram, "DirLight.Ambient"  ), 1, glm::value_ptr(m_directionalLight->getAmbient()));
	glUniform3fv(glGetUniformLocation(t_shaderProgram, "DirLight.Diffuse"  ), 1, glm::value_ptr(m_directionalLight->getDiffuse()));
	glUniform3fv(glGetUniformLocation(t_shaderProgram, "DirLight.Specular" ), 1, glm::value_ptr(m_directionalLight->getSpecular()));

	for(int i = 0; i < m_lights.size(); i++){
		t_result = t_light + std::to_string(i);
	    glUniform3fv(glGetUniformLocation(t_shaderProgram, (t_result + t_position).c_str()), 1, glm::value_ptr(m_lights[i]->getPosition()));
	    
	    glUniform3fv(glGetUniformLocation(t_shaderProgram, (t_result + t_ambient).c_str() ), 1, glm::value_ptr(m_lights[i]->getAmbient()));
	    glUniform3fv(glGetUniformLocation(t_shaderProgram, (t_result + t_diffuse).c_str() ), 1, glm::value_ptr(m_lights[i]->getDiffuse()));
	    glUniform3fv(glGetUniformLocation(t_shaderProgram, (t_result + t_specular).c_str()), 1, glm::value_ptr(m_lights[i]->getSpecular()));

		glUniform1f(glGetUniformLocation(t_shaderProgram, (t_result + t_atten).c_str()),  m_lights[i]->getAttenuation());
	}
}

void CEScene::draw(){
	calculateLights();
	m_root->draw();
}

void CEScene::release(){
	m_root->removeAllChilds();
	m_resourceManager->deleteResources();

	delete m_resourceManager;
	delete m_root;
}

void CEScene::remove(CESceneNode* p_node){
	m_root->removeChild(p_node);
}