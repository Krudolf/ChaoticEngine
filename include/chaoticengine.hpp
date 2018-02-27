
#ifndef CHAOTICENGINE
#define CHAOTICENGINE

//OpenGL
#include <glew.h>
#include <gl.h>
#include <glu.h>
#include <glut.h>
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
#include <manager/CEGLShader.hpp>

class ChaoticEngine{
public:
	ChaoticEngine();
	~ChaoticEngine();

	void initGL();

	void createWindow(int p_width, int p_height, const char* p_title, bool fullscreen);
	bool isWindowOpen();
	sf::RenderWindow* getWindow();

	void pushGLStates();
	void popGLStates();

	void eventHandler();
	void quad();

	CESceneNode* 	createNode(CESceneNode* p_father, CEEntity* p_entity);
	CETransform* 	createTransform();
	CECamera*		createCamera();
	CELight*		createLight(glm::vec3 p_intensities, float p_attenuation);
	CEMesh*			createMesh();

	void nodeMesh();

	CESceneNode* getRootNode();
	void draw();
	void release();

	void 			loadShader();
	void			setShadersPath(const char* vert_path, const char* frag_path);

	void cube();
	void displayGL();

private:
	sf::RenderWindow* 	m_window;
	sf::Event			m_event;
	sf::Clock			m_clock;

	CESceneNode*		m_root;
	CEResourceManager*	m_resourceManager;

	CEGLShader* 		m_loader;
	GLuint				m_shader;

	const char* m_vertex_path;
	const char* m_fragment_path;

	float angle;
};

#endif