
#include <../include/main.hpp>

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;

	//CREATE ALL NODES
	SceneNode* nodeRoot = new SceneNode("nodeRoot");

	SceneNode* nodeTrans1  = new SceneNode(nodeRoot, "nodeTrans1");
	SceneNode* nodeTrans11 = new SceneNode(nodeTrans1, "nodeTrans11");
	SceneNode* nodeMesh12  = new SceneNode(nodeTrans1, "nodeMesh12");
	SceneNode* nodeMesh111 = new SceneNode(nodeTrans11, "nodeMesh111");

	SceneNode* nodeTrans2  = new SceneNode(nodeRoot, "nodeTrans2");
	SceneNode* nodeTrans21 = new SceneNode(nodeTrans2, "nodeTrans21");
	SceneNode* nodeMesh22  = new SceneNode(nodeTrans2, "nodeMesh22");
	SceneNode* nodeMesh211 = new SceneNode(nodeTrans21, "nodeMesh211");


	//CREATE ALL ENTITIES
	Transform* 	trans1  = new Transform(1);
	Transform* 	trans11 = new Transform(11);
	Transform* 	trans2  = new Transform(2);
	Transform* 	trans21 = new Transform(21);

	Mesh*		mesh12  = new Mesh();
	Mesh*		mesh111 = new Mesh();
	Mesh*		mesh22  = new Mesh();
	Mesh*		mesh211 = new Mesh();

	//ASSIGN ENTITIES TO NODES
	nodeTrans1->setEntity(trans1);
	nodeTrans11->setEntity(trans11);
	nodeTrans2->setEntity(trans2);
	nodeTrans21->setEntity(trans21);

	nodeMesh12->setEntity(mesh12);
	nodeMesh111->setEntity(mesh111);
	nodeMesh22->setEntity(mesh22);
	nodeMesh211->setEntity(mesh211);

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
