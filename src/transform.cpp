
#include <iostream>
#include <stack>

#include <../include/transform.hpp>

std::stack<int> Entity::m_matrixStack;

glm::mat4 Entity::m_modelMatrix;
glm::mat4 Entity::m_viewMatrix;
glm::mat4 Entity::m_projectionMatrix;

Transform::Transform(int p_num) : Entity(){
	num = p_num;
}

Transform::~Transform(){}

void Transform::beginDraw(){
    std::cout << "Apilamos matriz de transformacion. Valor = " << num << std::endl;
    
    m_matrixStack.push(num);
}

void Transform::endDraw(){
    std::cout << "Desapilamos matriz de transformacion. Valor = " << m_matrixStack.top() << std::endl;
    //m_matrix = m_matrixStack().top();
    m_matrixStack.pop();
}