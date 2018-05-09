
#include <gtc/type_ptr.hpp>

#include "../include/CEparticle.hpp"
#include "../include/manager/CEresourceManager.hpp"

CEParticle::CEParticle(GLuint p_shaderProgram) : CEEntity(){
    m_shaderProgram = p_shaderProgram;
}

CEParticle::~CEParticle(){}

void CEParticle::beginDraw(){





	//PRECALCULAMOS LAS MATRICES Y LAS PASAMOS AL SHADER

	// glm::mat4 t_MVP = m_projectionMatrix * m_viewMatrix * m_modelMatrix;
    // glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "MVP"), 1, GL_FALSE, glm::value_ptr(t_MVP));
    
	// glm::mat4 t_modelView = m_viewMatrix * m_modelMatrix;
    // glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "ModelViewMatrix"), 1, GL_FALSE, glm::value_ptr(t_modelView));

    // glm::mat3 t_normal = transpose(inverse(m_modelMatrix));
    // glUniformMatrix3fv(glGetUniformLocation(m_shaderProgram, "NormalMatrix"), 1, GL_FALSE, glm::value_ptr(t_normal));

    // if(m_mesh != NULL)
    //     m_mesh->draw(m_shaderProgram);
}

void CEParticle::endDraw(){}

void CEParticle::update(double delta,glm::vec3 t_cameraPosition){
    // Simulate simple physics : gravity only, no collisions
    speed += glm::vec3(0.0f,-9.81f, 0.0f) * (float)delta * 0.5f;
    pos += speed * (float)delta;
    //antes era lenght2
    cameradistance = glm::length(pos - t_cameraPosition );
}

unsigned char* CEParticle::getColors(){
    unsigned char colors[4] = {r,g,b,a};
    return colors;
}