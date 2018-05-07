
#include "../include/CEskybox.hpp"
#include "../include/manager/CEresourceManager.hpp"
#include <iostream>

CESkybox::CESkybox(): CEEntity(){

    float x = 1.0f;
    float skyboxVertices[] = {
        // positions          
        -x,  x, -x,
        -x, -x, -x,
         x, -x, -x,
         x, -x, -x,
         x,  x, -x,
        -x,  x, -x,

        -x, -x,  x,
        -x, -x, -x,
        -x,  x, -x,
        -x,  x, -x,
        -x,  x,  x,
        -x, -x,  x,

         x, -x, -x,
         x, -x,  x,
         x,  x,  x,
         x,  x,  x,
         x,  x, -x,
         x, -x, -x,

        -x, -x,  x,
        -x,  x,  x,
         x,  x,  x,
         x,  x,  x,
         x, -x,  x,
        -x, -x,  x,

        -x,  x, -x,
         x,  x, -x,
         x,  x,  x,
         x,  x,  x,
        -x,  x,  x,
        -x,  x, -x,

        -x, -x, -x,
        -x, -x,  x,
         x, -x, -x,
         x, -x, -x,
        -x, -x,  x,
         x, -x,  x
    };
    // skybox VAO
    glGenVertexArrays(1, &m_skyboxVAO);
    glGenBuffers(1, &m_skyboxVBO);
    glBindVertexArray(m_skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

CESkybox::~CESkybox(){}

void CESkybox::beginDraw(){

    glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content

    //TODO: usar el shader del skybox desde aqui

    //set the View and Projection matrix to the shader
    //glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(m_viewMatrix));
    //glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));

    // skybox cube
   /* glBindVertexArray(m_skyboxVAO);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);*/
    
    glDepthFunc(GL_LESS); // set depth function back to default
}

void CESkybox::endDraw(){}

// loads a cubemap texture from 6 individual texture faces
// order:
// +X (right)
// -X (left)
// +Y (top)
// -Y (bottom)
// +Z (front) 
// -Z (back)
// -------------------------------------------------------
unsigned int CESkybox::loadCubemap(const char* p_texturesPath[6])
{
    CEResourceManager* t_manager = CEResourceManager::instance();

    std::cout<<"holaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;

    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    for (unsigned int i = 0; i < 6; i++)
    {
        CEResourceTexture* t_texture = static_cast<CEResourceTexture*>(t_manager->getResource(p_texturesPath[i]));
        unsigned char* data = t_texture->getTextureData(); 
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, t_texture->getTextureWidth(), t_texture->getTextureHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            t_texture->freeTextureData(data);
            m_texturesFaces[i] = t_texture;
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << p_texturesPath[i] << std::endl;
            t_texture->freeTextureData(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}