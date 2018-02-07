 
#ifndef SCENENODE
#define SCENENODE

#include <iostream>
#include <vector>
#include <entity.hpp>

class SceneNode{
public:
	SceneNode(const char* p_name);
	SceneNode(SceneNode* p_father, const char* p_name);
	virtual ~SceneNode();

	void release();

	void 	addChild(SceneNode* p_child);
	bool	removeChild(SceneNode* p_child);
	void 	removeAllChilds();

	void 	setEntity(Entity* p_entity);
	
	Entity*		getEntity();
	SceneNode* 	getFather();
	void 		setFather(SceneNode* p_father);

	void draw();


	int getTotalChilds();
	const char* getName();

private:
	Entity* 				m_entity;
	std::vector<SceneNode*>	m_childs;
	SceneNode* 				m_father;

	const char* m_name;
};

#endif