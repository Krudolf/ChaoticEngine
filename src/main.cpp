
#include <../include/main.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
	
	ChaoticEngine* engine = new ChaoticEngine();
	engine->createWindow(640, 480, "3KSC", false);

	const char* model = "resources_prueba/pelota/pelota.obj";
	const char* model1 = "resources_prueba/cubo/cubo.obj";
	const char* model2 = "resources_prueba/plataforma/Plataforma.obj";
	const char* model3 = "resources_prueba/life_tank/life_tank.obj";
	const char* model4 = "resources_prueba/mono.obj";

	GLuint t_shader = engine->loadShader();

	CESceneNode* light  = engine->createLight(glm::vec3(1,1,1), 0.0);
	CESceneNode* camera = engine->createCamera();
	CESceneNode* modelo = engine->loadModel(model2);
	//CESceneNode* modelo1 = engine->loadModel(model1);

	while(engine->isWindowOpen()){
		engine->processInput();
		/* ++++ MODELO ++++ */
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_R) == GLFW_PRESS)
			modelo->setRotation(0,3,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
			modelo->setTranslation(0,0.1,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
			modelo->setTranslation(0,-0.1,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
			modelo->setTranslation(0.1,0,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
			modelo->setTranslation(-0.1,0,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_E) == GLFW_PRESS)
			modelo->setTranslation(0,0,0.1);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_Q) == GLFW_PRESS)
			modelo->setTranslation(0,0,-0.1);
		//modelo->getPosition();

		/* ++++ CAMERA ++++ */
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_O) == GLFW_PRESS)
			camera->setRotation(0,1,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
			camera->setTranslation(0,0.1,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
			camera->setTranslation(0,-0.1,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
			camera->setTranslation(0.1,0,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
			camera->setTranslation(-0.1,0,0);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_M) == GLFW_PRESS)
			camera->setTranslation(0,0,0.1);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_N) == GLFW_PRESS)
			camera->setTranslation(0,0,-0.1);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_P) == GLFW_PRESS)
			static_cast<CECamera*>(camera->getEntity())->setPerspective(90.0f, 1.0f, 0.1f, 100.0f);
		if(glfwGetKey(engine->getWindow(), GLFW_KEY_L) == GLFW_PRESS)
			static_cast<CECamera*>(camera->getEntity())->setParallel(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
		//static_cast<CECamera*>(camera->getEntity())->setTarjet(modelo->getPosition());
		engine->setActiveCamera(camera);

		engine->clearWindow(0.5f, 0.0f, 0.0f, 1.0f);
		engine->draw();

    	engine->swapBuffers();
		engine->pollEvents();
	}
	engine->release();

	return 0;
}
