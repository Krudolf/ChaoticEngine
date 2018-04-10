
#include <../include/main.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
	
	ChaoticEngine* engine = new ChaoticEngine();
	engine->createWindow(640, 480, "3KSC", false);

	const char* model = "resources_prueba/fusfus/Plataforma_Fusfus.obj";

	const char* model2 = "resources_prueba/life_tank/life_tank.obj";

	GLuint t_shader = engine->loadShader();

	engine->createLight(glm::vec3(), 0.0);

	engine->createCamera();

	CESceneNode* modelo = engine->loadModel(model2);

	while(engine->isWindowOpen()){
		engine->processInput();
		
		engine->clearWindow(0.5f, 0.0f, 0.0f, 1.0f);

		modelo->setRotation(0,5,0);
		engine->draw();

    	engine->swapBuffers();
		engine->pollEvents();
	}
	engine->release();

	return 0;
}
