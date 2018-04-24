 
#ifndef CE_SCENE_CAMERA
#define CE_SCENE_CAMERA

#include <glm.hpp>

#include "../CEcamera.hpp"
#include "../CEtransform.hpp"
#include "../CEscenenode.hpp"

class CESceneCamera{
public:
	CESceneCamera(CESceneNode* p_parent, bool p_isActive);
	~CESceneCamera();

	bool 		getActive() 			{ return m_isActive; 	}
	void 		setActive(bool active) 	{ m_isActive = active; 	}

	void 		activateCamera();

private:
	CECamera*		m_camera;
	CETransform*	m_rotate;
	CETransform*	m_translate;

	bool			m_isActive;

	glm::mat4		getViewMatrix();
};

#endif
