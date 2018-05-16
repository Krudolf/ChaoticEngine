
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>

#include "../include/ChaoticEngine/CEsprite.hpp"
#include "../include/ChaoticEngine/manager/CEresourceManager.hpp"

CESprite::CESprite(const char* p_urlSource, float p_width, float p_height, GLuint p_shaderProgram) : CEEntity(){
    m_shaderProgram = p_shaderProgram;

    m_currentFrame = 0;
    m_totalFrames = 0;

    m_width   = p_width ;
    m_height  = p_height;

    float t_minX = m_width/2 * -1;
    float t_maxX = m_width/2;
    float t_minY = m_height/2 * -1;
    float t_maxY = m_height/2;

    GLfloat t_vertices[] = { 
        // Pos      // Tex
        t_minX, t_minY, 0.0f, 0.0f, 
        t_minX, t_maxY, 0.0f, 1.0f,
        t_maxX, t_maxY, 1.0f, 1.0f,
        t_maxX, t_minY, 1.0f, 0.0f
    };

    unsigned int m_indices[] = {
        0, 1, 3,  // First Triangle
        1, 2, 3   // Second Triangle
    };

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertices), t_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(0);
    
    std::cout << "CESprite creado" << std::endl;
}

CESprite::~CESprite(){}

void CESprite::beginDraw(){
    glUseProgram(m_shaderProgram);
    

    //PRECALCULAMOS LAS MATRICES Y LAS PASAMOS AL SHADER
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(m_modelMatrix));
    
    glm::mat4 t_projection = glm::ortho(20.0f, -20.0f, -20.0f, 20.0f, -15.0f, 100.0f);
    m_MVP = t_projection * m_viewMatrix * m_modelMatrix;
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(t_projection));
    //glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));

    glm::vec3 t_color = glm::vec3(1.0f, 1.0f, 1.0f);
    glUniform3f(glGetUniformLocation(m_shaderProgram, "spriteColor"), t_color.x, t_color.y, t_color.z);

    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture[m_currentFrame]->getTextureId());

    glBindVertexArray(m_VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void CESprite::endDraw(){}

void CESprite::loadResource(const char* p_urlSource){
    CEResourceManager* t_manager = CEResourceManager::instance();
    CEResourceTexture* t_resource = (CEResourceTexture*)&t_manager->getResource(p_urlSource);
    if(t_resource != NULL){
        m_texture.push_back(t_resource);
        m_texture.back()->glBuffersTexture();
        m_totalFrames = m_texture.size();
    }
}

void CESprite::getNext(){
    m_currentFrame++;
    if(m_currentFrame > m_totalFrames)
        m_currentFrame = 0;
}

void CESprite::getLast(){
    m_currentFrame--;
    if(m_currentFrame < 0)
        m_currentFrame = m_totalFrames;
}