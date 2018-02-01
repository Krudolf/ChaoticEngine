
#include <iostream>
#include <vector>
#include <../include/scenenode.hpp>
#include <../include/entity.hpp>

#include <cstdint>
#include <iomanip>

void printHexVal(uint16_t val) {
   std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
}

//====================================================================================
// Print a memory slice as raw bytes
//====================================================================================
void printRawMem(uint8_t* p, uint16_t linebytes, uint16_t lines) { 
   for(uint16_t l=0; l < lines; ++l) {
      std::cout << reinterpret_cast<uint16_t*>(p) << " ";
      for(uint16_t u=0; u < linebytes; ++u) {
         printHexVal(*p);
         ++p;
         std::cout << " ";
      }
      std::cout << "\n";
   }
}


int main(){
	uint8_t* p;
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;
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

	std::cout << "Root: " << root << std::endl;
	std::cout << "Child11 dame a tu padre: " << child11->getFather() << std::endl;
	std::cout << "Child12 dame a tu padre: " << child12->getFather() << std::endl;
	std::cout << "Child13 dame a tu padre: " << child13->getFather() << std::endl;

	std::cout << "\nBORRAMOS CHILD1" << std::endl;
	root->removeChild(child1);

	std::cout << "Child11: " << child11 << std::endl;
	std::cout << "Child11 dame a tu padre: " << child11->getFather() << std::endl;

	return 0;
}