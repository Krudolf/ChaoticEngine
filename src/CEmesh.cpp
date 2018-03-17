
#include <iostream>
#include <iomanip>
#include <stack>
#include <glm.hpp>
#include <../include/CEmesh.hpp>
#include <../include/manager/CEresourceManager.hpp>

CEMesh::CEMesh(GLuint p_shaderProgram) : CEEntity(){
    m_shaderProgram = p_shaderProgram;
}

CEMesh::~CEMesh(){}

void CEMesh::beginDraw(){

    if(m_mesh != NULL){
        m_mesh->draw(m_modelMatrix, m_shaderProgram);
    }
}

void CEMesh::endDraw(){}

void CEMesh::loadResource(const char* p_urlSource){
    CEResourceManager* t_manager = CEResourceManager::instance();
    CEResource* t_resource = t_manager->getResource(p_urlSource);
    if(t_resource != NULL){
        m_mesh = (CEResourceMesh*)t_resource;
    }
}