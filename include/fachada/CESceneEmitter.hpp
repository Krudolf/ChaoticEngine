#ifndef CE_SCENE_EMITTER
#define CE_SCENE_EMITTER

#include <glew.h>
#include <glfw3.h>

#include "../CEmesh.hpp"
#include "../CEtransform.hpp"
#include "../CEscenenode.hpp"
#include "../CEemitter.hpp"

class CESceneEmitter{
public:
	CESceneEmitter();
	~CESceneEmitter();

	void	processInput(GLFWwindow* p_window);

	void 	setScale(float p_x, float p_y, float p_z);
	void 	setRotation(float p_x, float p_y, float p_z);
	void 	setPosition(float p_x, float p_y, float p_z);

	void 	setAbsoluteScale(float p_x, float p_y, float p_z);
	void 	setAbsoluteRotation(float p_x, float p_y, float p_z);
	void 	setAbsolutePosition(float p_x, float p_y, float p_z);

	void	getPosition();

private:
	CEemitter*	    m_emitter;
	CETransform*	m_rotate;
	CETransform*	m_scale;
	CETransform*	m_translate;

};

#endif