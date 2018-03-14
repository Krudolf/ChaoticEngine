
#include <../include/main.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
	
	ChaoticEngine* engine = new ChaoticEngine();
	engine->createWindow(640, 480, "3KSC", false);

	//Crea un nodo hoja mesh con dos transformaciones padre(rotate->translate->mesh)
	//engine->nodeMesh();
	//engine->loadShader();

	/*//Crea un nodo hoja mesh al que se le asigna un modelo
	const char* model = "resources_prueba/coso.obj";
	engine->loadModel(model);*/

	//----------------------------------------------------------
	//engine->draw();
	//MAIN LOOP
	engine->shaderProgram();
	engine->createTriangle();
	while(engine->isWindowOpen()){
		engine->processInput();
		
		engine->clearWindow(0.5f, 0.0f, 0.0f, 1.0f);

		//engine->useProgram();
		engine->drawTriangle();

    	engine->swapBuffers();
		engine->pollEvents();
	}
	engine->terminate();
	engine->release();

	return 0;
}
