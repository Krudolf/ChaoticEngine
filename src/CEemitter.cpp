
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>

#include "../include/CEemitter.hpp"
#include "../include/manager/CEresourceManager.hpp"

CEEmitter::CEEmitter(const char* p_url, GLuint p_shaderProgram) : CEEntity(){
    m_shaderProgram = p_shaderProgram;
    m_amount = 1000;

    loadResource(p_url);
    m_texture->glBuffersTexture();
    init();
}

void CEEmitter::init(){
    GLfloat t_vertices[] = { 
        // Pos      // Tex
        0.0f, 0.0f, 0.0f, 0.0f, 
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
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

    //Create m_amount default particle instances
    for(GLuint i = 0; i < m_amount; i++)
        m_particles.push_back(Particle());
}

//Render all particles
void CEEmitter::beginDraw(){
    glUseProgram(m_shaderProgram);

    for(Particle particle : m_particles){
        if(particle.Life > 0.0f){
            glm::mat4 t_projection = glm::ortho(20.0f, -20.0f, -20.0f, 20.0f, -15.0f, 100.0f);
            glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(t_projection));
            //glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));

            glUniform2f(glGetUniformLocation(m_shaderProgram, "offset"), particle.Position.x, particle.Position.y);
            glUniform4f(glGetUniformLocation(m_shaderProgram, "color"), particle.Color.x, particle.Color.y, particle.Color.z, particle.Color.w);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, m_texture->getTextureId());

            glBindVertexArray(m_VAO);
            //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
        }
    }
}

void CEEmitter::endDraw(){}

void CEEmitter::Update(GLfloat dt, GLuint newParticles, glm::vec2 offset){
    //Add new particles 
    for(GLuint i = 0; i < newParticles; i++){
        GLuint unusedParticle = firstUnusedParticle();
        respawnParticle(m_particles[unusedParticle], offset);
    }
    //Update all particles
    for(GLuint i = 0; i < m_amount; i++){
        Particle &p = m_particles[i];
        p.Life -= dt; //reduce life
        if(p.Life > 0.0f){  //particle is alive, thus update
            p.Position -= p.Velocity * dt; 
            p.Color.a -= dt * 2.5;
        }
    }
}

//Stores the index of the last particle used (for quick access to next dead particle)
GLuint lastUsedParticle = 0;
GLuint CEEmitter::firstUnusedParticle(){
    //First search from last used particle, this will usually return almost instantly
    for(GLuint i = lastUsedParticle; i < m_amount; i++){
        if(m_particles[i].Life <= 0.0f){
            lastUsedParticle = i;
            return i;
        }
    }
    //Otherwise, do a linear search
    for(GLuint i = 0; i < lastUsedParticle; i++){
        if(m_particles[i].Life <= 0.0f){
            lastUsedParticle = i;
            return i;
        }
    }
    //All particles are taken, override the first one (note that if it repeatedly hits this case, more particles should be reserved)
    lastUsedParticle = 0;
    return 0;
}

void CEEmitter::respawnParticle(Particle &particle, glm::vec2 offset){
    GLfloat random = ((rand() % 100) - 50) / 10.0f;
    GLfloat rColor = 0.5 + ((rand() % 100) / 100.0f);
    
    glm::vec2 Position = glm::vec2(0.0f,0.0f);
    glm::vec2 Velocity = glm::vec2(0.0f,-5.0f);
    
    //particle.Position   = Position + random + offset;
    particle.Position   = Position;
    particle.Color      = glm::vec4(rColor, rColor, rColor, 1.0f);
    particle.Life       = 1.0f;
    particle.Velocity   = Velocity * 1.0f;
}

void CEEmitter::loadResource(const char* p_urlSource){
    std::cout << p_urlSource << std::endl;
    CEResourceManager* t_manager = CEResourceManager::instance();
    CEResource* t_resource = t_manager->getResource(p_urlSource);
    if(t_resource != 0){
        m_texture = (CEResourceTexture*)t_resource;
    }

}