 
#ifndef CE_SCENE_LIGHT
#define CE_SCENE_LIGHT

#include <glm.hpp>

#include "../CElight.hpp"
#include "../CEtransform.hpp"
#include "../CEscenenode.hpp"

class CESceneLight{
public:
	CESceneLight(CESceneNode* p_parent, glm::vec3 p_intensities, float p_attenuation, GLuint p_shaderProgram, bool p_isActive = false);
	~CESceneLight();

	bool 		getActive() 			{ return m_isActive; 	}
	void 		setActive(bool active) 	{ m_isActive = active; 	}


private:
	CELight*		m_light;
	CETransform*	m_rotate;
	CETransform*	m_translate;

	glm::vec3 		m_intensities;
	float			m_attenuation;

	bool			m_isActive;
};

#endif
