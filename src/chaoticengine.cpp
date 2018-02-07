

#include <iostream>

#include <../include/chaoticengine.hpp> 

ChaoticEngine::ChaoticEngine(){}

ChaoticEngine::~ChaoticEngine(){}

void ChaoticEngine::createWindow(int p_width, int p_height, const char* p_title, bool fullscreen){
// Inicializar GLFW
	if(!glfwInit())
	    fprintf( stderr, "Error al inicializar GLFW\n" );

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Queremos OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Para hacer feliz a MacOS ; Aunque no debería ser necesaria
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //No queremos el viejo OpenGL 

	if(fullscreen){
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);

		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		m_window = glfwCreateWindow(mode->width, mode->height, p_title, monitor, NULL);		
	}else{
		m_window = glfwCreateWindow(p_width, p_height, p_title, NULL, NULL);
	}

	glfwMakeContextCurrent(m_window); // Inicializar GLEW
/*
	16x16, 32x32 and 48x48
	GLFWimage images[2];
	images[0] = load_icon("my_icon.png");
	images[1] = load_icon("my_icon_small.png");
	glfwSetWindowIcon(m_window, 2, images);
*/

	if(m_window == NULL){
	    fprintf(stderr, "Falla al abrir una ventana GLFW. Si GPU Intel prueba con OpenGL 2.2\n");
	    glfwTerminate();
	}

	glewExperimental=true; // Se necesita en el perfil de base.
	if(glewInit() != GLEW_OK)
	    fprintf(stderr, "Fallo al inicializar GLEW\n");

	// Capturar la tecla ESC cuando sea presionada
	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
}

bool ChaoticEngine::isWindowOpen(){
	return glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0;
}

void ChaoticEngine::swapBuffers(){
	// Intercambiar buffers
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void ChaoticEngine::terminate(){
	glfwTerminate();
}