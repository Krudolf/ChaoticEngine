
#include <gtc/type_ptr.hpp>
#include "../include/CEemitter.hpp"
#include "../include/manager/CEresourceManager.hpp"

CEEmitter::CEEmitter(GLuint shader) : CEEntity()
{
    this->shader = shader;
    amount = 500;
    loadResource("resources/particula.jpg");
    this->init();
}

void CEEmitter::Update(GLfloat dt, GLuint newParticles, glm::vec2 offset)
{
    // Add new particles 
    for (GLuint i = 0; i < newParticles; ++i)
    {
        int unusedParticle = this->firstUnusedParticle();
        this->respawnParticle(this->particles[unusedParticle], offset);
    }
    // Update all particles
    for (GLuint i = 0; i < this->amount; ++i)
    {
        Particle &p = this->particles[i];
        p.Life -= dt; // reduce life
        if (p.Life > 0.0f)
        {	// particle is alive, thus update
            p.Position -= p.Velocity * dt; 
            p.Color.a -= dt * 2.5;
        }
    }
}

// Render all particles
void CEEmitter::beginDraw()
{
    // Use additive blending to give it a 'glow' effect
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glUseProgram(shader);
    for (Particle particle : this->particles)
    {
        if (particle.Life > 0.0f)
        {
           // this->shader.SetVector2f("offset", particle.Position);
            glUniform2f(glGetUniformLocation(shader, "offset"), particle.Position.x, particle.Position.y);
            glUniform4f(glGetUniformLocation(shader, "color"), particle.Color.x, particle.Color.y, particle.Color.z, particle.Color.w);
            //this->texture.Bind(); 
            //glBindTexture(GL_TEXTURE_2D, this->ID);
            texture->glBuffersTexture();
            glBindVertexArray(this->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            glBindVertexArray(0);
        }
    }
    // Don't forget to reset to default blending mode
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void CEEmitter::endDraw(){}


void CEEmitter::init()
{
    // Set up mesh and attribute properties
    GLuint VBO;
    GLfloat particle_quad[] = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    }; 
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(this->VAO);
    // Fill mesh buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(particle_quad), particle_quad, GL_STATIC_DRAW);
    // Set mesh attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindVertexArray(0);

    // Create this->amount default particle instances
    for (GLuint i = 0; i < this->amount; ++i)
        this->particles.push_back(Particle());
}

// Stores the index of the last particle used (for quick access to next dead particle)
GLuint lastUsedParticle = 0;
GLuint CEEmitter::firstUnusedParticle()
{
    // First search from last used particle, this will usually return almost instantly
    for (GLuint i = lastUsedParticle; i < this->amount; ++i){
        if (this->particles[i].Life <= 0.0f){
            lastUsedParticle = i;
            return i;
        }
    }
    // Otherwise, do a linear search
    for (GLuint i = 0; i < lastUsedParticle; ++i){
        if (this->particles[i].Life <= 0.0f){
            lastUsedParticle = i;
            return i;
        }
    }
    // All particles are taken, override the first one (note that if it repeatedly hits this case, more particles should be reserved)
    lastUsedParticle = 0;
    return 0;
}

void CEEmitter::respawnParticle(Particle &particle, glm::vec2 offset)
{
    GLfloat random = ((rand() % 100) - 50) / 10.0f;
    GLfloat rColor = 0.5 + ((rand() % 100) / 100.0f);
     glm::vec2 Position = glm::vec2(0.0f,0.0f);///posiciones de mierdas
    glm::vec2 Velocity = glm::vec2(0.0f,0.0f);
    particle.Position = Position + random + offset;
    particle.Color = glm::vec4(rColor, rColor, rColor, 1.0f);
    particle.Life = 1.0f;
    particle.Velocity = Velocity * 0.1f;
}

void CEEmitter::loadResource(const char* p_urlSource){
    CEResourceManager* t_manager = CEResourceManager::instance();
    CEResource* t_resource = t_manager->getResource(p_urlSource);
    if(t_resource != NULL)
        texture = (CEResourceTexture*)t_resource;
}