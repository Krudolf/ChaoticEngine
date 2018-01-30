
#include <include/scenenode.hpp> 

SceneNode::SceneNode(){}

SceneNode::~SceneNode(){
	delete this;
}

void SceneNode::addChild(SceneNode* p_child){
	m_childs.push_back(p_child);
}

bool SceneNode::removeChild(SceneNode* p_child){
	for(int i = 0; i < m_childs.size(); i++){
		if(m_childs.at(i) == p_child){
			delete m_childs.at(i);
			m_childs.erase(i);
			return true;
		}
	}
	return false;
}

void SceneNode::removeAllChilds(){
	for(int i = 0; i < m_childs.size(); i++){
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

void SceneNode::draw(){
	m_entity->beginDraw();
	for(int i = 0; i < m_childs.size(); i++){
		m_childs.at(i)->draw();
	}
	m_entity->endDraw();
}
