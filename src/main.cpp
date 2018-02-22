
#include <../include/main.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;

	ChaoticEngine* engine = new ChaoticEngine();

	//Crea un nodo hoja mesh con dos transformaciones padre(rotate->translate->mesh)
	engine->nodeMesh();

	engine->draw();

	engine->createWindow(640, 480, "3KSC", true);
/*
	Comentar si quieremos ver la ventana!!
*/
	engine->closeWindow();
	//MAIN LOOP
	while(engine->isWindowOpen()){
		sf::Event event;
        while (engine->getWindow()->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                engine->closeWindow();
            }
        }
	    //Dibujamos con OpenGL


	    engine->pushGLStates();
	    //Dibujamos con SFML


	    engine->popGLStates();
	    //Dibujamos con OpenGL
	    engine->getWindow()->clear();
	    //engine->getWindow()->draw();
	    engine->getWindow()->display();
	}

	engine->release();

	return 0;
}
