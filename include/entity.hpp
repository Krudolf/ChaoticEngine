 
#ifndef ENTITY
#define ENTITY

#include <stack>

#include <glm.hpp>

/*Virtual class*/
class Entity{
public:
	virtual void beginDraw() = 0;
	virtual void endDraw() = 0;

protected:
	//En la pila tenemos que guardar puntero a las matrices, no las matrices enteras
	static std::stack<int> m_matrixStack;
	//static std::stack<glm::mat4*> m_matrixStack;
	//Son glm
	static glm::mat4 m_modelMatrix;
	static glm::mat4 m_viewMatrix;
	static glm::mat4 m_projectionMatrix;

private:

};



#endif