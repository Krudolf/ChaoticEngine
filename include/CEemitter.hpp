#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <CEentity.hpp>
#include "manager/CEresourceTexture.hpp"


// Represents a single particle and its state
struct Particle {
    glm::vec2 Position, Velocity;
    glm::vec4 Color;
    GLfloat Life;
    Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) { }
};


// CEEmitter acts as a container for rendering a large number of 
// particles by repeatedly spawning and updating particles and killing 
// them after a given amount of time.
class CEEmitter : public CEEntity
{
public:
    // Constructor
    CEEmitter(GLuint shader);
    // Update all particles
    void Update(GLfloat dt = 0.025f, GLuint newParticles = 20, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
    // Render all particles
    void beginDraw();
    void endDraw();
    void loadResource(const char* p_urlSource);
private:
    // State
    std::vector<Particle> particles;
    GLuint amount;
    // Render state
    GLuint shader;
    CEResourceTexture *texture;
    GLuint VAO;
    // Initializes buffer and vertex attributes
    void init();
    // Returns the first Particle index that's currently unused e.g. Life <= 0.0f or 0 if no particle is currently inactive
    GLuint firstUnusedParticle();
    // Respawns particle
    void respawnParticle(Particle &particle, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
};

#endif