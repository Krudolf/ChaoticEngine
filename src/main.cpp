
#include <../include/main.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;

	//CREATE ALL NODES
	CESceneNode* nodeRoot = new CESceneNode("nodeRoot");

	CESceneNode* nodeTrans1  = new CESceneNode(nodeRoot, "nodeTrans1");
	CESceneNode* nodeTrans11 = new CESceneNode(nodeTrans1, "nodeTrans11");
	CESceneNode* nodeMesh12  = new CESceneNode(nodeTrans1, "nodeMesh12");
	CESceneNode* nodeMesh111 = new CESceneNode(nodeTrans11, "nodeMesh111");
	//CESceneNode* nodeLight112 = new CESceneNode(nodeTrans11, "nodeLight112");

	CESceneNode* nodeTrans2  = new CESceneNode(nodeRoot, "nodeTrans2");
	CESceneNode* nodeTrans21 = new CESceneNode(nodeTrans2, "nodeTrans21");
	CESceneNode* nodeMesh22  = new CESceneNode(nodeTrans2, "nodeMesh22");
	CESceneNode* nodeMesh211 = new CESceneNode(nodeTrans21, "nodeMesh211");
	//CESceneNode* nodeLight212 = new CESceneNode(nodeTrans21, "nodeLight212");


	//CREATE ALL ENTITIES
	CETransform* 	trans1  = new CETransform();
	CETransform* 	trans11 = new CETransform();
	CETransform* 	trans2  = new CETransform();
	CETransform* 	trans21 = new CETransform();

	CEMesh*		mesh12  = new CEMesh();
	CEMesh*		mesh111 = new CEMesh();
	CEMesh*		mesh22  = new CEMesh();
	CEMesh*		mesh211 = new CEMesh();

	CELight* 	light112 = new CELight(glm::vec3(1,0,0), 0.8f);
	CELight* 	light212 = new CELight(glm::vec3(0.8,1,0), 0.5f);

	//ASSIGN ENTITIES TO NODES
	nodeTrans1->setEntity(trans1);
	nodeTrans11->setEntity(trans11);
	nodeTrans2->setEntity(trans2);
	nodeTrans21->setEntity(trans21);

	nodeMesh12->setEntity(mesh12);
	nodeMesh111->setEntity(mesh111);
	nodeMesh22->setEntity(mesh22);
	nodeMesh211->setEntity(mesh211);

	//nodeLight112->setEntity(light112);
	//nodeLight212->setEntity(light212);


	//APLICAMOS TRANSFORMACIONES
	trans1->translate(10, 10, 10);
	trans11->translate(200, 200, 200);
    trans2->rotate(0, 0, 45);



	//DIBUJADO DEL ARBOL
	std::cout << "\nDIBUJAMOS ARBOL DE LA ESCENA" << std::endl;
	nodeRoot->draw();

/*
    //TRANSFORMACIONES
    std::cout << std::endl << "TRANSFORMATIONS" << std::endl;
    std::cout << "Identity" << std::endl;
    trans1->showMatrix();

    std::cout << "Translate" << std::endl;
    trans1->translate(1, 2, 3);
    //trans1->transpose();
    trans1->showMatrix();
    
    std::cout << "Identity" << std::endl;
    trans1->loadIdentity();
    trans1->showMatrix();
    
    std::cout << "Rotate" << std::endl;
    trans1->rotate(0, 0, 30);
    //trans1->transpose();
    trans1->showMatrix();
    
    std::cout << "Identity" << std::endl;
    trans1->loadIdentity();
    trans1->showMatrix();

    std::cout << "Scale" << std::endl;
    trans1->scale(1, 2, 3);
    trans1->showMatrix();
*/

	//CARGA DE RECURSOS
	CEResourceManager* manager = new CEResourceManager();
	const char* resource = "resources_prueba/life_tank.obj";
	const char* resource2 = "resources_prueba/life_tank.obj";
	
	manager->getResource(resource);
	manager->getResource(resource2);


	ChaoticEngine* engine = new ChaoticEngine();

	engine->createWindow(640, 480, "3KSC", false);

	//MAIN LOOP
	while(engine->isWindowOpen()){
	    
	    engine->swapBuffers();
	}

	engine->terminate();
	
	return 0;
}
