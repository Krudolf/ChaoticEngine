
#include <iostream>
#include <stack>
#include <../include/CEmesh.hpp>

CEMesh::CEMesh() : CEEntity(){}

CEMesh::~CEMesh(){}

void CEMesh::beginDraw(){
	std::cout << "Dibujamos una malla" << std::endl;
	std::cout << "Valor de la matrixModel: " << m_matrixStack.top() << std::endl;
}

void CEMesh::endDraw(){}