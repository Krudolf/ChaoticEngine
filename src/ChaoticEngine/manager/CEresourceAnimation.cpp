
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

	std::ifstream t_file(p_name);
    std::string t_line;
    const char* t_path;

    while(std::getline(t_file, t_line)){
        if(t_line == "" || t_line[0] == '#')// Skip everything and continue with the next line
            continue;

        //const char* t_path = t_line.c_str();
        std::cout << t_line << std::endl;
    }
}


void CEResourceAnimation::draw(GLuint p_shaderProgram){
	for(GLuint i = 0; i < m_meshes.size(); i++){
			//m_meshes[i].subDraw(p_shaderProgram);
	}
}