
#include <iostream>

#include <../include/chaoticengine.hpp> 

ChaoticEngine::ChaoticEngine(){
	m_root = new CESceneNode("root");
	m_resourceManager = new CEResourceManager();
}

ChaoticEngine::~ChaoticEngine(){}

void ChaoticEngine::createWindow(int p_width, int p_height, const char* p_title, bool fullscreen){
	m_window = new sf::RenderWindow(sf::VideoMode(p_width, p_height), p_title);
}

bool ChaoticEngine::isWindowOpen(){
	return m_window->isOpen();
}

sf::RenderWindow* ChaoticEngine::getWindow(){
	return m_window;
}

void ChaoticEngine::pushGLStates(){
	m_window->pushGLStates();
}

void ChaoticEngine::popGLStates(){
	m_window->popGLStates();
}

void ChaoticEngine::eventHandler(){
	sf::Event t_event;
	while(m_window->pollEvent(t_event)){
		switch(t_event.type){
			case sf::Event::Closed:
				m_window->close();
			break;
		}
    }
}

/*
			**************************************
			* FUNCTION FOR CREATE THE SCENE TREE *
			**************************************
*/

CESceneNode* ChaoticEngine::createNode(CESceneNode* p_father, CEEntity* p_entity){
	CESceneNode* t_node = new CESceneNode(p_father, "node");
	t_node->setEntity(p_entity);

	return t_node;
}

CETransform* ChaoticEngine::createTransform(){
	CETransform* t_transform = new CETransform();

	return t_transform;
}

CECamera* ChaoticEngine::createCamera(){
	CECamera* t_camera = new CECamera();

	return t_camera;
}

CELight* ChaoticEngine::createLight(glm::vec3 p_intensities, float p_attenuation){
	CELight* t_light = new CELight(p_intensities, p_attenuation);

	return t_light;
}

CEMesh* ChaoticEngine::createMesh(){
	CEMesh* t_mesh = new CEMesh();

	return t_mesh;
}

CESceneNode* ChaoticEngine::getRootNode(){
	return m_root;
}


void ChaoticEngine::draw(){
	m_root->draw();
}

void ChaoticEngine::release(){
	m_root->removeAllChilds();
	//m_resourceManager->PONER_EL_METODO_DE_BORRADO_DE_MANU();

	delete m_resourceManager;
	delete m_root;
}

void ChaoticEngine::nodeMesh(){
	CETransform* 	trans1  = createTransform();
	CETransform* 	trans11 = createTransform();

	CEMesh*			mesh111 = createMesh();

	trans1 ->rotate(0, 45, 0);
	trans11->translate(200, 200, 200);

	CESceneNode* nodeTrans1  = createNode(getRootNode(), trans1);
	CESceneNode* nodeTrans11 = createNode(nodeTrans1, trans11);
	CESceneNode* nodeMesh111 = createNode(nodeTrans11, mesh111);
}
