
#include <iostream>
#include <../include/mesh.hpp>

Mesh::Mesh() : Entity(){}

Mesh::~Mesh(){}

void Mesh::beginDraw(){
	std::cout << "Dibujamos una malla" << std::endl;
}

void Mesh::endDraw(){}