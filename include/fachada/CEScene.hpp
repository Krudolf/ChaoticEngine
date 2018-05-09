 
#ifndef CE_SCENE
#define CE_SCENE

#include <vector>

#include "../CEscenenode.hpp"
#include "../manager/CEresourceManager.hpp"
#include "../../include/CEskybox.hpp"

class CESceneCamera;
class CESceneLight;
class CESceneMesh;
class CEShaderProgram;
class CEEmitter;

class CEScene{
public:
	CEScene();
	~CEScene();

	CESceneCamera*	createCamera(bool p_isActive = false);
	CESceneLight*	createLight();
	CESceneMesh*	createMesh(const char* p_path);
	CESkybox*		createSkybox(const char* p_texturesPath[6]);//0->right, 1->left, 2->top, 3->bottom, 4->front, 5->back
	CEEmitter*		createEmitter(const char* p_url);

	void			setActiveCamera(CESceneCamera* p_camera);

	void 			draw();
	void			release();

private:
	CESceneNode*		m_root;
	CEResourceManager*	m_resourceManager;
	CEShaderProgram* 	m_shaderProgram;

	CESceneCamera*		m_activeCamera;

	std::vector<CESceneCamera*>	m_cameras;
	std::vector<CESceneLight*>	m_lights;
};

#endif
