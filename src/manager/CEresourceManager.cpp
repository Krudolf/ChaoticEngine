
#include <../../include/manager/CEresourceManager.hpp>
#include <../../include/CEresourceMesh.hpp>
#include <iostream>
#include <string>

CEResourceManager::CEResourceManager(){}

CEResourceManager::~CEResourceManager(){}

CEResource* CEResourceManager::getResource(const char* p_name){
	CEResource *t_resource = NULL;
	for(int i = 0; i < m_resources.size(); i++){
		//if the resource is in the vector
		if(m_resources[i]->getName() == p_name){
			t_resource = m_resources[i];
			std::cout<<"ya estaba en la lista"<<std::endl;
			return t_resource;
		}
	} 
	if(t_resource == NULL){
		std::cout<<"No estaba en la lista"<<std::endl;
		//check the format of the resource
		std::string path = p_name;
		std::string format = path.substr(path.find_last_of('.')+1, path.size());

		//if the resource is a mesh
		if(format.compare("obj") == 0 || format.compare("blend") == 0){
			t_resource = new CEResourceMesh();
			t_resource->setName(p_name);
			std::cout<<"voy a cargar el archivo"<<std::endl;
			t_resource->loadFile(p_name);
			std::cout<<"ya lo he cargado"<<std::endl;
			m_resources.push_back(t_resource);
		}
	}
	return t_resource;
}
