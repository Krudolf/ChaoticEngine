
#ifndef CHAOTICENGINE
#define CHAOTICENGINE

//OpenGL
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <CEentity.hpp>
#include <CEcamera.hpp>
#include <CElight.hpp>
#include <CEmesh.hpp>
#include <CEscenenode.hpp>
#include <CEtransform.hpp>

#include <manager/CEresourceManager.hpp>

class ChaoticEngine{
public:
	ChaoticEngine();
	~ChaoticEngine();

	void createWindow(int p_width, int p_height, const char* p_title, bool fullscreen);
	void closeWindow();
	bool isWindowOpen();
	sf::RenderWindow* getWindow();

	void pushGLStates();
	void popGLStates();

	bool pollEvent();

	CESceneNode* 	createNode(CESceneNode* p_father, CEEntity* p_entity);
	CETransform* 	createTransform();
	CECamera*		createCamera();
	CELight*		createLight(glm::vec3 p_intensities, float p_attenuation);
	CEMesh*			createMesh();

	void nodeMesh();

	CESceneNode* getRootNode();
	void draw();
	void release();
	
private:
	sf::RenderWindow* 	m_window;
	sf::Event			m_event;

	CESceneNode*		m_root;
	CEResourceManager*	m_resourceManager;
};

#endif