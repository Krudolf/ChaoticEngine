
#include <iostream>
#include <stack>

#include <../include/CEtransform.hpp>

std::stack<int> CEEntity::m_matrixStack;

glm::mat4 CEEntity::m_modelMatrix;
glm::mat4 CEEntity::m_viewMatrix;
glm::mat4 CEEntity::m_projectionMatrix;

CETransform::CETransform(int p_num) : CEEntity(){
	num = p_num;
}

CETransform::~CETransform(){}

void CETransform::beginDraw(){
    std::cout << "Apilamos matriz de transformacion. Valor = " << num << std::endl;
    
    m_matrixStack.push(num);
}

void CETransform::endDraw(){
    std::cout << "Desapilamos matriz de transformacion. Valor = " << m_matrixStack.top() << std::endl;
    //m_matrix = m_matrixStack().top();
    m_matrixStack.pop();
}