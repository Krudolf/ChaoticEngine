 
#ifndef CESCENENODE
#define CESCENENODE

#include <iostream>
#include <vector>
#include <CEentity.hpp>

class CESceneNode{
public:
	CESceneNode(const char* p_name);
	CESceneNode(CESceneNode* p_father, const char* p_name);
	virtual ~CESceneNode();

	void release();

	void 	addChild(CESceneNode* p_child);
	bool	removeChild(CESceneNode* p_child);
	void 	removeAllChilds();

	void 	setEntity(CEEntity* p_entity);
	
	CEEntity*		getEntity();
	CESceneNode* 	getFather();
	void 		setFather(CESceneNode* p_father);

	void draw();


	int getTotalChilds();
	const char* getName();

private:
	CEEntity* 					m_entity;
	std::vector<CESceneNode*>	m_childs;
	CESceneNode* 				m_father;

	const char* m_name;
};

#endif