
#include <../include/main.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
	
	ChaoticEngine* engine = new ChaoticEngine();
	engine->createWindow(640, 480, "3KSC", false);
	
	GLuint t_shader = engine->loadShader();

	engine->createLight(glm::vec3(), 0.0);

	engine->createCamera();

	engine->loadModel("resources_prueba/life_tank/life_tank.blend");

	while(engine->isWindowOpen()){
		engine->processInput();
		
		engine->clearWindow(0.5f, 0.0f, 0.0f, 1.0f);

		//engine->drawTriangle();
/*
		glm::mat4 trans;
		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f));
		trans = glm::scale(trans, glm::vec3(0.3, 0.3, 0.3)); 

		unsigned int transformLoc = glGetUniformLocation(t_shader, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
*/
		engine->draw();

    	engine->swapBuffers();
		engine->pollEvents();
	}
	engine->release();

	return 0;
}
