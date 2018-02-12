#include <../include/CEtransform.hpp>
#include <gtc/matrix_transform.hpp> //For glm transformations
#include <stack>
#include <iostream>
#include <iomanip>

std::stack<int> CEEntity::m_matrixStack;

glm::mat4 CEEntity::m_modelMatrix;
glm::mat4 CEEntity::m_viewMatrix;
glm::mat4 CEEntity::m_projectionMatrix;

//Constructor
CETransform::CETransform(int p_num) : CEEntity(){
    loadIdentity();
	m_num = p_num;
}

//Destructor
CETransform::~CETransform(){}

//Loads identity matrix
void CETransform::loadIdentity(){
    m_matrix = glm::mat4();
}

//Loads custom matrix
void CETransform::loadMatrix(glm::mat4 p_matrix){
    m_matrix = p_matrix;
}

//Prints the matrix in the console
void CETransform::showMatrix(){   
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << m_matrix[i][j] << "\t";
        }
        
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

//Trasposes the transform matrix
void CETransform::transpose(){
    m_matrix = glm::transpose(m_matrix);
}

//Trasposes the given matrix
glm::mat4 CETransform::transpose(glm::mat4 p_matrix){
    return glm::transpose(p_matrix);
}

//Applies a traslation to the matrix
//Receives the offset for each axis
void CETransform::translate(float p_tx, float p_ty, float p_tz){
    m_matrix = glm::translate(m_matrix, glm::vec3(p_tx, p_ty, p_tz));
}

//Applies a rotation to the matrix
//Receives the rotation for each axis
void CETransform::rotate(float p_rx, float p_ry, float p_rz){
    m_matrix = glm::rotate(m_matrix, p_rx, glm::vec3(1, 0, 0));
    m_matrix = glm::rotate(m_matrix, p_ry, glm::vec3(0, 1, 0));
    m_matrix = glm::rotate(m_matrix, p_rz, glm::vec3(0, 0, 1));
}

//Applies an scale to the matrix
//Receives the ratio for each axis
void CETransform::scale (float p_sx, float p_sy, float p_sz){
    m_matrix = glm::scale(m_matrix, glm::vec3(p_sx, p_sy, p_sz));
}


void CETransform::beginDraw(){
    std::cout << "Apilamos matriz de transformacion. Valor = " << m_num << std::endl;
    
    m_matrixStack.push(m_num);
}

void CETransform::endDraw(){
    std::cout << "Desapilamos matriz de transformacion. Valor = " << m_matrixStack.top() << std::endl;
    //m_matrix = m_matrixStack().top();
    m_matrixStack.pop();
}