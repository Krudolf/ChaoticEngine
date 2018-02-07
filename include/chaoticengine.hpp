
#ifndef CHAOTICENGINE
#define CHAOTICENGINE

//OpenGL
#include <glew.h>
#include <glfw3.h>
//#include <glm.hpp>

class ChaoticEngine{
public:
	ChaoticEngine();
	~ChaoticEngine();

	void createWindow(int p_width, int p_height, const char* p_title, bool fullscreen);
	bool isWindowOpen();
	void swapBuffers();

	void terminate();

private:
	GLFWwindow* m_window;
};

#endif