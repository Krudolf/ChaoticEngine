 
#ifndef SCENENODE
#define SCENENODE

#include <iostream>
#include <vector>
#include <entity.hpp>

class SceneNode{
public:
	SceneNode();
	virtual ~SceneNode();

	void 	addChild(SceneNode* p_child);
	bool	removeChild(SceneNode* p_child);
	void 	removeAllChilds();

	bool 	setEntity(Entity* p_entity);
	
	Entity*		getEntity();
	SceneNode* 	getFather();

	void draw();

private:
	Entity* 			m_entity;
	vector<SceneNode*> 	m_childs;
	SceneNode* 			m_father;
};

#endif