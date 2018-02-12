#include <iostream>
#include <../include/CElight.hpp>

CELight::CELight(glm::vec3 p_position) : CEEntity(){
	position = p_position;
}

CELight::~CELight(){}

void CELight::beginDraw(){
	std::cout<<"Dibujamos luz en la posicion" << posicion << std::endl;
}

void CEMesh::endDraw(){}