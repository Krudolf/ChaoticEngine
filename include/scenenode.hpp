 
#ifndef SCENENODE
#define SCENENODE

#include <iostream>
#include <vector>
#include <entity.hpp>

class SceneNode{
public:
	SceneNode();
	SceneNode(SceneNode* p_father);
	virtual ~SceneNode();

	void release();

	void 	addChild(SceneNode* p_child);
	bool	removeChild(SceneNode* p_child);
	void 	removeAllChilds();

	bool 	setEntity(Entity* p_entity);
	
	Entity*		getEntity();
	SceneNode* 	getFather();
	void 		setFather(SceneNode* p_father);

	void draw();


	int getTotalChilds();

private:
	Entity* 			m_entity;
	std::vector<SceneNode*> 	m_childs;
	SceneNode* 			m_father;
};

#endif