
#include <../../include/manager/CEresourceManager.hpp>

#include <assimp/Importer.hpp>      // C++ importer interface

CEResourceManager::CEResourceManager(){}

CEResourceManager::~CEResourceManager(){}

CEResource* CEResourceManager::getResource(const char* p_name){
	CEResource *t_resource = NULL;
	for(int i = 0; i < m_resources.size(); i++){
		if(m_resources[i]->getName() == p_name){
			t_resource = m_resources[i];
			std::cout<<"ya estaba en la lista"<<std::endl;
			return t_resource;
		}
	}
	if(t_resource == NULL){
		std::cout<<"No estaba en la lista"<<std::endl;
		t_resource = new CEResource();
		t_resource->setName(p_name);
		//t_resource->loadFile(p_name);
		m_resources.push_back(t_resource);
	}
	return t_resource;
}
