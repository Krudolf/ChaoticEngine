
#include <../include/main.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
	
	ChaoticEngine* engine = new ChaoticEngine();
	engine->createWindow(640, 480, "3KSC", false);

	//Crea un nodo hoja mesh con dos transformaciones padre(rotate->translate->mesh)
	//engine->nodeMesh();

	//Crea un nodo hoja mesh al que se le asigna un modelo
	const char* model = "resources_prueba/life_tank.blend";
	engine->loadModel(model);

	//engine->shaderProgram();
	GLuint t_shader = engine->loadShader();
	engine->createCube();
	engine->createTriangle();

	glm::vec3 t_intensities;
	float t_attenuation = 0;
	engine->createLight(t_intensities, t_attenuation);
	engine->createCamera();

	while(engine->isWindowOpen()){
		engine->processInput();
		
		engine->clearWindow(0.5f, 0.0f, 0.0f, 1.0f);

		engine->drawTriangle();
		//engine->draw();

    	engine->swapBuffers();
		engine->pollEvents();
	}
	engine->release();

	return 0;
}
