
#ifndef CEPARTICLE
#define CEPARTICLE

#include <glew.h>

#include "CEentity.hpp"
#include "manager/CEresourceMesh.hpp"

class CEParticle : public CEEntity{
public:
	CEParticle(GLuint p_shaderProgram);
	virtual ~CEParticle();

	//void loadResource(const char* p_urlSource);

	void beginDraw() override;
	void endDraw()   override;

	void update(double p_delta, glm::vec3 p_cameraPosition);

	void setLife(float p_life){life = p_life;};
	void setCameraDistance(float p_cameradistance){cameradistance = p_cameradistance;};
	
	glm::vec3 getPos(){return pos;};
	float getSize(){return size;};
	float getLife(){return life;};
	unsigned char* getColors();
	//glm::mat4	getModelMatrix()	{ return m_modelMatrix;	};

private:
	GLuint m_shaderProgram;
	glm::vec3 pos, speed;
	unsigned char r,g,b,a; // Color
	float size, angle, weight;
	float life; // Remaining life of the particle. if <0 : dead and unused.
	float cameradistance; // *Squared* distance to the camera. if dead : -1.0f

	bool operator<(const CEParticle& that) const {
		// Sort in reverse order : far particles drawn first.
		//return this->cameradistance > that.cameradistance;
	}
};

#endif