
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
	CEResource* t_resource = NULL;
	std::cout<< "Se ha solicitado el recurso: " << p_name << std::endl;
	for(int i = 0; i < m_resources.size(); i++){
		//if the resource is in the vector
		if(m_resources[i]->getName() == p_name){
			t_resource = m_resources[i];
			std::cout<<"ya estaba en la lista, lo recupero"<<std::endl;
			//resource was found
			return t_resource;
		}
	} 
	//Resource not found, we wanna load it from disk
	if(t_resource == NULL){
		std::cout<<"No estaba en la lista, lo solicito"<<std::endl;
		//check the format of the resource
		t_resource = checkFormat(p_name);
		t_resource->setName(p_name);
		if(t_resource->loadFile(p_name)){
			std::cout<<"Recurso creado, puede cogerlo"<<std::endl;
			m_resources.push_back(t_resource);
		}
	}
	return t_resource;
}

CEResource* CEResourceManager::checkFormat(const char* p_name){
	
	std::string t_path   = p_name;
	std::string t_format = t_path.substr(t_path.find_last_of('.')+1, t_path.size());

	//Default NULL
	CEResource* t_resourceObject = NULL; 
	
	//Remember even = format, odd = type
	size_t i = 0;
	while (i < m_types.size() && t_resourceObject == NULL) {

		if (!m_types.at(i).compare(t_format)) {
			std::cout<<"El recurso es de tipo: " << m_types.at(i + 1) <<std::endl;
			if (!m_types.at(i + 1).compare("mesh")) { //file contains a mesh			
				t_resourceObject = new CEResourceMesh();
				//TODO distinguir entre mallas animadas y estaticas
			}
			else if (!m_types.at(i + 1).compare("tex")) {//file contains a texture
				t_resourceObject = new CEResourceTexture();
			}
		}
		i += 2;
	}

	return t_resourceObject;
}

void CEResourceManager::deleteResources(){
	std::cout<<std::endl;
	std::cout<<"Borrar todos los recursos"<<std::endl;
	for(int i = 0; i < m_resources.size(); i++){
		delete(m_resources[i]);
		m_resources[i] = nullptr;
    }
    
	m_resources.clear();
}

void CEResourceManager::showResources(){
	std::cout<<std::endl;
	std::cout<<"Lista de recursos"<<std::endl;
	for(int i = 0; i < m_resources.size(); i++){
		std::cout<<"recurso: " << m_resources[i]->getName() <<std::endl;
	}
}