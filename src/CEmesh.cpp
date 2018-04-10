
#include <iostream>
#include <iomanip>
#include <stack>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

#include <../include/CEmesh.hpp>
#include <../include/manager/CEresourceManager.hpp>

void showMatrix2(glm::mat4 p_matrix){   
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

CEMesh::CEMesh(GLuint p_shaderProgram) : CEEntity(){
    m_shaderProgram = p_shaderProgram;
}

CEMesh::~CEMesh(){}

void CEMesh::beginDraw(){
	//PRECALCULAMOS LAS MATRICES Y LAS PASAMOS AL SHADER
	/*std::cout << "++++++++++++++++\n";
	showMatrix2(m_projectionMatrix);
	showMatrix2(m_viewMatrix);
	showMatrix2(m_modelMatrix);*/

	glm::mat4 t_MVP = m_projectionMatrix * m_viewMatrix * m_modelMatrix;
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "MVP"), 1, GL_FALSE, glm::value_ptr(t_MVP));
    
	glm::mat4 t_modelView = m_viewMatrix * m_modelMatrix;
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ModelViewMatrix"), 1, GL_FALSE, glm::value_ptr(t_modelView));

    if(m_mesh != NULL)
        m_mesh->draw(m_modelMatrix, m_shaderProgram);
}

void CEMesh::endDraw(){}

void CEMesh::loadResource(const char* p_urlSource){
    CEResourceManager* t_manager = CEResourceManager::instance();
    CEResource* t_resource = t_manager->getResource(p_urlSource);
    if(t_resource != NULL)
        m_mesh = (CEResourceMesh*)t_resource;
}