
#include <../include/scenenode.hpp> 

SceneNode::SceneNode(){
	m_father = NULL;
}

SceneNode::SceneNode(SceneNode* p_father){
	m_father = p_father;
	m_father->addChild(this);
}

//Si quiero puedo poner todos los atributos a 0 (no es necesario)
SceneNode::~SceneNode(){}

void SceneNode::addChild(SceneNode* p_child){
	m_childs.push_back(p_child);
	p_child->setFather(this);
}

/*Removes a child, and all the childs of his child.*/
bool SceneNode::removeChild(SceneNode* p_child){
	for(int i = 0; i < m_childs.size(); i++){
		if(m_childs.at(i) == p_child){
			m_childs.at(i)->removeAllChilds();
			m_childs.at(i) = 0;
			delete m_childs.at(i);
			m_childs.erase(m_childs.begin()+(i));
			return true;
		}
	}
	return false;
}

/*Removes all childs of the father and all the childs of his childs*/
void SceneNode::removeAllChilds(){
	for(int i = 0; i < m_childs.size(); i++){
		m_childs.at(i)->removeAllChilds();
		std::cout << "BORRAMOS " << m_childs.at(i) << std::endl;
		m_childs.at(i) = 0;
		delete m_childs.at(i);
	}
	m_childs.clear();
}

bool SceneNode::setEntity(Entity* p_entity){}

Entity* SceneNode::getEntity(){
	return m_entity;
}

SceneNode* SceneNode::getFather(){
	return m_father;
}

void SceneNode::setFather(SceneNode* p_father){
	m_father = p_father;
}

void SceneNode::draw(){
	m_entity->beginDraw();
	for(int i = 0; i < m_childs.size(); i++){
		m_childs.at(i)->draw();
	}
	m_entity->endDraw();
}

int SceneNode::getTotalChilds(){
	return m_childs.size();
}