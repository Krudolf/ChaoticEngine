
#include <../include/main.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
	
	ChaoticEngine* engine = new ChaoticEngine();
	engine->createWindow(640, 480, "3KSC", false);

	//Crea un nodo hoja mesh con dos transformaciones padre(rotate->translate->mesh)
	//engine->nodeMesh();

	//Crea un nodo hoja mesh al que se le asigna un modelo
	const char* model1 = "resources_prueba/plup/plupTex.obj";
	//engine->loadModel(model1);

	const char* model = "resources_prueba/fusfus/Plataforma_Fusfus.obj";
	//engine->loadModel(model1);

	const char* model2 = "resources_prueba/life_tank/life_tank.obj";
	engine->loadModel(model);

	//engine->shaderProgram();
	GLuint t_shader = engine->loadShader();
	//engine->createCube();
	//engine->createTriangle();

	glm::vec3 t_intensities;
	float t_attenuation = 0;
	engine->createLight(t_intensities, t_attenuation);
	engine->createCamera();

	while(engine->isWindowOpen()){
		engine->processInput();
		
		engine->clearWindow(0.5f, 0.0f, 0.0f, 1.0f);

		//engine->drawTriangle();
		glm::mat4 trans;
		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		trans = glm::scale(trans, glm::vec3(0.05, 0.05, 0.05)); 

		unsigned int transformLoc = glGetUniformLocation(t_shader, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		engine->draw();

    	engine->swapBuffers();
		engine->pollEvents();
	}
	engine->release();

	return 0;
}
