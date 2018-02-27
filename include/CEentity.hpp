 
#ifndef CEENTITY
#define CEENTITY

#include <stack>

#include <glm.hpp>

/*Virtual class*/
class CEEntity{
public:
	virtual ~CEEntity() = default;
	virtual void beginDraw() = 0;
	virtual void endDraw() = 0;

protected:
	static std::stack<glm::mat4> m_matrixStack;

	static glm::mat4 m_modelMatrix;
	static glm::mat4 m_viewMatrix;
	static glm::mat4 m_projectionMatrix;

private:

};

#endif