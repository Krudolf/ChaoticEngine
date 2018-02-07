
#include <iostream>
#include <stack>

#include <../include/transform.hpp>

Transform::Transform() : Entity(){}

Transform::~Transform(){}

void Transform::beginDraw(){
    std::cout << "Apilamos matriz de transformacion" << std::endl;
    //m_matrixStack.push(m_matrix);
}

void Transform::endDraw(){
    std::cout << "Desapilamos matriz de transformacion" << std::endl;
    //m_matrix = m_matrixStack.top();
    //m_matrixStack.pop();
}