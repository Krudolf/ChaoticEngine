
#include <../include/scenenode.hpp> 
#include <../include/transform.hpp>
#include <../include/mesh.hpp>

SceneNode::SceneNode(const char* p_name){
	m_name = p_name;
	m_father = NULL;

	std::cout << "Creado el nodo " << m_name << std::endl;
}

SceneNode::SceneNode(SceneNode* p_father, const char* p_name){
	m_name = p_name;
	m_father = p_father;
	m_father->addChild(this);

	std::cout << "Creado el nodo " << m_name << ". Su padre es " << m_father->getName() << std::endl;
}

//Si quiero puedo poner todos los atributos a 0 (no es necesario)
SceneNode::~SceneNode(){}

void SceneNode::addChild(SceneNode* p_child){
	m_childs.push_back(p_child);
	p_child->setFather(this);
}

/*Removes a child, and all the childs of his child.*/
bool SceneNode::removeChild(SceneNode* p_child){
	std::cout << this->getName() << " va a eliminar a su hijo " << p_child->getName() << std::endl;
	for(int i = 0; i < m_childs.size(); i++){
		if(m_childs.at(i) == p_child){
			std::cout << p_child->getName() << " localizado." << std::endl;
			m_childs.at(i)->removeAllChilds();
			m_childs.at(i) = 0;
			delete m_childs.at(i);
			m_childs.erase(m_childs.begin()+(i));
			std::cout << p_child->getName() << " borrado." << std::endl;
			return true;
		}
	}
	return false;
}

/*Removes all childs of the father and all the childs of his childs*/
void SceneNode::removeAllChilds(){
	for(int i = 0; i < m_childs.size(); i++){
		m_childs.at(i)->removeAllChilds();
		std::cout << m_childs.at(i)->getName() << " borrado." << std::endl;
		m_childs.at(i) = 0;
		delete m_childs.at(i);
	}
	m_childs.clear();
}

void SceneNode::setEntity(Entity* p_entity){
	m_entity = p_entity;
}

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
	if(m_entity != NULL){
		std::cout << "------------------------\n" << m_name << " empieza draw." << std::endl;
		m_entity->beginDraw();
	}
	for(int i = 0; i < m_childs.size(); i++){
		m_childs.at(i)->draw();
	}
	if(m_entity != NULL){
		m_entity->endDraw();
		std::cout << m_name << " termina draw." << std::endl;
	}
}

int SceneNode::getTotalChilds(){
	return m_childs.size();
}

const char* SceneNode::getName(){
	return m_name;
}
