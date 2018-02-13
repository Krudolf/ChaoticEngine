
#include <iostream>
#include <iomanip>
#include <stack>
#include <glm.hpp>
#include <../include/CEmesh.hpp>

void showMatrix(glm::mat4 p_matrix){   
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << p_matrix[i][j] << "\t";
        }   
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


CEMesh::CEMesh() : CEEntity(){}

CEMesh::~CEMesh(){}

void CEMesh::beginDraw(){
	std::cout << "Dibujamos una malla" << std::endl;
	std::cout << "Valor de la matrixModel:" << std::endl;
	showMatrix(m_modelMatrix);
}

void CEMesh::endDraw(){}