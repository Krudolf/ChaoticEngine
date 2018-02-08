
#include <iostream>
#include <stack>
#include <../include/mesh.hpp>

Mesh::Mesh() : Entity(){}

Mesh::~Mesh(){}

void Mesh::beginDraw(){
	std::cout << "Dibujamos una malla" << std::endl;
	std::cout << "Valor de la matrixModel: " << m_matrixStack.top() << std::endl;
}

void Mesh::endDraw(){}