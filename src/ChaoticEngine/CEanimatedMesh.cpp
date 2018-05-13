
#include <gtc/type_ptr.hpp>
#include <iomanip>
#include <iostream>

#include "../include/ChaoticEngine/CEanimatedMesh.hpp"
#include "../include/ChaoticEngine/manager/CEresourceManager.hpp"

/*void showMat(glm::mat4 p_matrix){   
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << p_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}*/

CEAnimatedMesh::CEAnimatedMesh(GLuint p_shaderProgram) : CEEntity(){
    m_shaderProgram = p_shaderProgram;
}

CEAnimatedMesh::~CEAnimatedMesh(){}

void CEAnimatedMesh::beginDraw(){
    glUseProgram(m_shaderProgram);
    
	//PRECALCULAMOS LAS MATRICES Y LAS PASAMOS AL SHADER
	m_MVP = m_projectionMatrix * m_viewMatrix * m_modelMatrix;
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "MVP"), 1, GL_FALSE, glm::value_ptr(m_MVP));
    
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(m_modelMatrix));
    
	glm::mat4 t_modelView = m_viewMatrix * m_modelMatrix;
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ModelViewMatrix"), 1, GL_FALSE, glm::value_ptr(t_modelView));

    glm::mat4 t_viewProj = m_viewMatrix * m_projectionMatrix;
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ViewProjection"), 1, GL_FALSE, glm::value_ptr(t_viewProj));

    glm::mat3 t_normal = transpose(inverse(m_modelMatrix));
    glUniformMatrix3fv(glGetUniformLocation(m_shaderProgram, "NormalMatrix"), 1, GL_FALSE, glm::value_ptr(t_normal));

    //showMat(m_modelMatrix);

    //TODO aqui hay que hacer el ajuste del tiempo para calcular el frame

    /*if(m_animations[i] != NULL)
        m_animations[i]->draw(m_shaderProgram);*/
}

void CEAnimatedMesh::endDraw(){}

void CEAnimatedMesh::loadResource(const char* p_urlSource){
    CEResourceManager* t_manager = CEResourceManager::instance();
    CEResource* t_resource = t_manager->getResource(p_urlSource);
    if(t_resource != NULL)
        m_animations.push_back((CEResourceAnimation*)t_resource);
}