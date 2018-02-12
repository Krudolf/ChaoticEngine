
#include <../include/main.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;

	//CREATE ALL NODES
	CESceneNode* nodeRoot = new CESceneNode("nodeRoot");

	CESceneNode* nodeTrans1  = new CESceneNode(nodeRoot, "nodeTrans1");
	CESceneNode* nodeTrans11 = new CESceneNode(nodeTrans1, "nodeTrans11");
	CESceneNode* nodeMesh12  = new CESceneNode(nodeTrans1, "nodeMesh12");
	CESceneNode* nodeMesh111 = new CESceneNode(nodeTrans11, "nodeMesh111");
	CESceneNode* nodeLight112 = new CESceneNode(nodeTrans11, "nodeLight112");

	CESceneNode* nodeTrans2  = new CESceneNode(nodeRoot, "nodeTrans2");
	CESceneNode* nodeTrans21 = new CESceneNode(nodeTrans2, "nodeTrans21");
	CESceneNode* nodeMesh22  = new CESceneNode(nodeTrans2, "nodeMesh22");
	CESceneNode* nodeMesh211 = new CESceneNode(nodeTrans21, "nodeMesh211");
	CESceneNode* nodeLight212 = new CESceneNode(nodeTrans21, "nodeLight212");


	//CREATE ALL ENTITIES
	CETransform* 	trans1  = new CETransform(1);
	CETransform* 	trans11 = new CETransform(11);
	CETransform* 	trans2  = new CETransform(2);
	CETransform* 	trans21 = new CETransform(21);

	CEMesh*		mesh12  = new CEMesh();
	CEMesh*		mesh111 = new CEMesh();
	CEMesh*		mesh22  = new CEMesh();
	CEMesh*		mesh211 = new CEMesh();

	CELight* 	light112 = new CELight(glm::vec3(100, 20, 3));
	CELight* 	light212 = new CELight(glm::vec3(50, 100, 56));

	//ASSIGN ENTITIES TO NODES
	nodeTrans1->setEntity(trans1);
	nodeTrans11->setEntity(trans11);
	nodeTrans2->setEntity(trans2);
	nodeTrans21->setEntity(trans21);

	nodeMesh12->setEntity(mesh12);
	nodeMesh111->setEntity(mesh111);
	nodeMesh22->setEntity(mesh22);
	nodeMesh211->setEntity(mesh211);

	nodeLight112->setEntity(light112);
	nodeLight212->setEntity(light212);

	//DIBUJADO DEL ARBOL
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
