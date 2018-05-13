
#include <glm.hpp>
#include <iostream>

#include "../../include/ChaoticEngine/manager/CEresourceManager.hpp"
#include "../../include/ChaoticEngine/manager/CEresourceAnimation.hpp"

//Constructor
CEResourceAnimation::CEResourceAnimation() : CEResource(){}

//Destructor
CEResourceAnimation::~CEResourceAnimation(){}

bool CEResourceAnimation::loadFile(const char* p_name){
	//TODO hacer lectura de fichero
}


void CEResourceAnimation::draw(GLuint p_shaderProgram){
	for(GLuint i = 0; i < m_meshes.size(); i++){
			m_meshes[i].subDraw(p_shaderProgram);
	}
}