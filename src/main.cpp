
#include <iostream>
#include <vector>
#include <../include/scenenode.hpp>
#include <../include/transform.hpp>

#include <../include/chaoticengine.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;

	//CREATE ALL NODES
	SceneNode* nodeRoot = new SceneNode("nodeRoot");

	SceneNode* nodeTrans1 = new SceneNode(nodeRoot, "nodeTrans1");

	SceneNode* nodeTrans11 = new SceneNode(nodeTrans1, "nodeTrans11");
	SceneNode* nodeChild12 = new SceneNode(nodeTrans1, "nodeChild12");

	SceneNode* nodeChild111 = new SceneNode(nodeTrans11, "nodeChild111");

	//CREATE ALL ENTITIES
	Transform* trans1 = new Transform();

	Transform* trans11 = new Transform();

	//ASSIGN ENTITIES TO NODES
	nodeTrans1->setEntity(trans1);

	nodeTrans11->setEntity(trans11);


	std::cout << "\nDIBUJAMOS ARBOL DE LA ESCENA" << std::endl;
	nodeRoot->draw();

/*
	ChaoticEngine* engine = new ChaoticEngine();

	engine->createWindow(640, 480, "3KSC", true);

	//MAIN LOOP
	while(engine->isWindowOpen()){
	    
	    engine->swapBuffers();
	}

	engine->terminate();
*/
	return 0;
}
