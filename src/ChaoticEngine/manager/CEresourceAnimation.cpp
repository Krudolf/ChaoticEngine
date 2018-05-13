
#include <glm.hpp>
#include <iostream>

#include "../../include/ChaoticEngine/manager/CEresourceManager.hpp"
#include "../../include/ChaoticEngine/manager/CEresourceAnimation.hpp"

#include <fstream>
#include <sstream>
#include <string>

//Constructor
CEResourceAnimation::CEResourceAnimation() : CEResource(){}

//Destructor
CEResourceAnimation::~CEResourceAnimation(){}

bool CEResourceAnimation::loadFile(const char* p_name){
	CEResourceManager* t_manager = CEResourceManager::instance();

	std::ifstream t_file(p_name);
    std::string t_line;
    const char* t_path;

    while(std::getline(t_file, t_line)){
        if(t_line == "" || t_line[0] == '#')// Skip everything and continue with the next line
            continue;

        t_path = t_line.c_str();
        //CEResourceMesh* t_mesh = static_cast<CEResourceMesh*>(t_manager->getResource(t_path));
        m_meshes.push_back(static_cast<CEResourceMesh*>(t_manager->getResource(t_path)));
    meshList();
    }
}

void CEResourceAnimation::meshList(){
	std::cout << "Recursos de la animacion: " << this->getName() << " con " << getNumFrames() << " recursos"<< std::endl;
	for(int i = 0; i < m_meshes.size(); i++){
		if(m_meshes[i] != NULL)
			std::cout << " - " << m_meshes[i]->getName() << std::endl;
	} 
}

void CEResourceAnimation::draw(GLuint p_shaderProgram){
	for(GLuint i = 0; i < m_meshes.size(); i++){
		if(m_meshes[i] != NULL && m_meshes[i]->getName() != ""){
			m_meshes[i]->draw(p_shaderProgram);
		}
	}
}