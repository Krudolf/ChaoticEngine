
#include <iostream>
#include <iomanip>
#include <stack>
#include <glm.hpp>
#include <../include/CEmesh.hpp>
#include <../include/manager/CEresourceManager.hpp>

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

    if(m_mesh != NULL){
        m_mesh->draw();
    }
}

void CEMesh::endDraw(){}

void CEMesh::loadResource(const char* p_urlSource){

    CEResourceManager *t_manager = CEResourceManager::instance();
    CEResource *t_resource = t_manager->getResource(p_urlSource);
    if(t_resource != NULL){
        m_mesh = (CEResourceMesh*)t_resource;
    }
}