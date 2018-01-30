
#include <iostream>
#include <vector>
#include <../include/scenenode.hpp>
#include <../include/entity.hpp>

int main(){
	/*
	std::cout << "Total hijos de root: " << root->getTotalChilds() << std::endl;
	std::cout << "Dame a tu padre: " << child1->getFather() << std::endl;
	*/

	SceneNode* root = new SceneNode();

	SceneNode* child1 = new SceneNode(root);
	SceneNode* child2 = new SceneNode(root);
	SceneNode* child11 = new SceneNode(child1);
	SceneNode* child12 = new SceneNode(child1);
	SceneNode* child13 = new SceneNode(child1);

	std::cout << "Root:            " << root << std::endl;
	std::cout << "Dame a tu padre: " << child1->getFather() << std::endl;
	root->removeChild(child11);
	std::cout << "Dame a tu padre: " << child1->getFather() << std::endl;



	std::cout << "HASTA LUEGOR!" << std::endl;
	return 0;
}