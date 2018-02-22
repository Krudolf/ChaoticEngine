
#include <../../include/manager/CEresourceManager.hpp>
#include <../../include/CEresourceMesh.hpp>
#include <string>

//Instance initialization
CEResourceManager* CEResourceManager::m_instance = 0;

//Returns the only instance of this class
CEResourceManager* CEResourceManager::instance(){
    if (!m_instance){
        m_instance = new CEResourceManager();
    }

    return m_instance;
}

CEResourceManager::CEResourceManager(){}

CEResourceManager::~CEResourceManager(){}

CEResource* CEResourceManager::getResource(const char* p_name){
	CEResource *t_resource = NULL;
	std::cout<< "Se ha solicitado el recurso: " << p_name << std::endl;
	for(int i = 0; i < m_resources.size(); i++){
		//if the resource is in the vector
		if(m_resources[i]->getName() == p_name){
			t_resource = m_resources[i];
			std::cout<<"ya estaba en la lista, lo recupero"<<std::endl;
			return t_resource;
		}
	} 
	if(t_resource == NULL){
		std::cout<<"No estaba en la lista, lo solicito"<<std::endl;
		//check the format of the resource
		std::string path = p_name;
		std::string format = path.substr(path.find_last_of('.')+1, path.size());

		//if the resource is a mesh
		if(format.compare("obj") == 0 || format.compare("blend") == 0){
			t_resource = new CEResourceMesh();
			t_resource->setName(p_name);
			if(t_resource->loadFile(p_name)){
				std::cout<<"Recurso creado, puede cogerlo"<<std::endl;
				m_resources.push_back(t_resource);
			}
		}
	}
	return t_resource;
}

void CEResourceManager::deleteResources(){

	std::cout<<std::endl;
	std::cout<<"Borrar todos los recursos"<<std::endl;
	m_resources.clear();
}

void CEResourceManager::showResources(){

	std::cout<<std::endl;
	std::cout<<"Lista de recursos"<<std::endl;
	for(int i = 0; i < m_resources.size(); i++){
		std::cout<<"recurso: " << m_resources[i]->getName() <<std::endl;
	}
}