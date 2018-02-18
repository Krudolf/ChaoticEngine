
#include <../../include/manager/CEresourceManager.hpp>

#include <assimp/Importer.hpp>      // C++ importer interface

CEResourceManager::CEResourceManager(){}

CEResourceManager::~CEResourceManager(){}

CEResource* CEResourceManager::getResource(const char* p_name){
	CEResource *t_resource = NULL;
	for(int i = 0; i < m_resources.size(); i++){
		//Tenemos que buscar el recurso en el vector
	}
	if(t_resource == NULL){
		//t_resource = new CEResource();
		//t_resource->loadFile(p_name);
		m_resources.push_back(t_resource);
	}
	return t_resource;
}
