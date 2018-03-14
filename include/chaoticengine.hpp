
#ifndef CHAOTICENGINE
#define CHAOTICENGINE

//OpenGL
#include <glew.h>
#include <gl.h>
//#include <glu.h>
//#include <glut.h>
#include <glfw3.h>
#include <glm.hpp>

#include <SFML/Graphics.hpp>
//#include <SFML/OpenGL.hpp>

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

	void createWindow(int p_width, int p_height, const char* p_title, bool p_fullscreen);
	bool isWindowOpen();
	void closeWindow();
	void clearWindow(float p_red, float p_green, float p_blue, float p_alpha);
	GLFWwindow* getWindow();

	void render();

	static void windows_size_callback(GLFWwindow* p_window, int p_width, int p_height);

	void swapBuffers();
	void pollEvents();

	void processInput();

	void terminate();

	void shaderProgram();
	void useProgram(); 
	
	void createTriangle();
	void drawTriangle();


	void quad();

/* ----- ARBOL -----*/

	CESceneNode* 	createNode(CESceneNode* p_father, CEEntity* p_entity);
	
    //Transformations
    CETransform* 	createTransform();
    CETransform*    translate(float p_tx, float p_ty, float p_tz);
    CETransform*    rotate(float p_rx, float p_ry, float p_rz);
    CETransform*    scale (float p_sx, float p_sy, float p_sz);
	
    CECamera*		createCamera();
	CELight*		createLight(glm::vec3 p_intensities, float p_attenuation);
	CEMesh*			createMesh();

	void nodeMesh();

	CESceneNode* getRootNode();
	void draw();
	void release();

	void 			loadShader();
	void			setShadersPath(const char* vert_path, const char* frag_path);
	void 			loadModel(const char* p_path);

	void createVertexBuffer();
	void renderBuffers();
	void displayGL();

private:
	GLFWwindow* 		m_window;
	sf::Event			m_event;
	sf::Clock			m_clock;

	CESceneNode*		m_root;
	CEResourceManager*	m_resourceManager;

	CEGLShader* 		m_loader;
	GLuint				m_shaderProgram;

    uint m_VBO, m_VAO, m_EBO;

	//GLuint				m_VBO;

	const char* m_vertex_path;
	const char* m_fragment_path;

	float angle;
};

#endif