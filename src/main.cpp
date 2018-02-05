
#include <iostream>
#include <vector>
#include <../include/scenenode.hpp>
#include <../include/entity.hpp>

//OpenGL
#include <glew.h>
#include <glfw3.h>
//#include <glm/glm.hpp>

bool initGLFW(){
	// Inicializar GLFW
	if(!glfwInit()){
	    fprintf( stderr, "Error al inicializar GLFW\n" );
	    return false;
	}
	return true;
}

GLFWwindow* createWindow(){
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Queremos OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Para hacer feliz a MacOS ; Aunque no debería ser necesaria
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //No queremos el viejo OpenGL 

	//Crear una ventana y su contexto OpenGL
	GLFWwindow* window = glfwCreateWindow( 800, 600, "3KSC", NULL, NULL);
	glfwMakeContextCurrent(window); // Inicializar GLEW

	return window;
}

bool checkWindow(GLFWwindow* p_window){
	if(p_window == NULL){
	    fprintf(stderr, "Falla al abrir una ventana GLFW. Si GPU Intel prueba con OpenGL 2.2\n");
	    glfwTerminate();
	    return false;
	}
	return true;
}

bool initGLEW(){
	glewExperimental=true; // Se necesita en el perfil de base.
	if(glewInit() != GLEW_OK){
	    fprintf(stderr, "Fallo al inicializar GLEW\n");
	    return false;
	}
	return true;
}

bool isWindowOpen(GLFWwindow* p_window){
	return glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(p_window) == 0;
}

int main(){
	//uint8_t* p;
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;


	if(!initGLFW())
		return -1;

	GLFWwindow* window;
	window = createWindow();

	if(!checkWindow(window))
		return -1;

	if(!initGLEW())
		return -1;

	// Capturar la tecla ESC cuando sea presionada
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	/*MAIN LOOP*/
	// Revisar que la tecla ESC fue presionada y cerrar la ventana
	while(isWindowOpen(window)){
	    
	    // Intercambiar buffers
	    glfwSwapBuffers(window);
	    glfwPollEvents();
	}


	return 0;
}
