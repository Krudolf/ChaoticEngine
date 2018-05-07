
#include <../include/main.hpp>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "../include/manager/stb_image.h"

int main(){
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl;

	CEWindow* window = new CEWindow(640, 480, "3KSC", false);

	CEScene* scene = new CEScene();
	CESceneCamera* m_camera	= scene->createCamera(true);
	CESceneLight*  m_light	= scene->createLight();
	CESceneMesh*   m_mesh	= scene->createMesh("resources/pelota/pelota.obj");
	//0->right, 1->left, 2->top, 3->bottom, 4->front, 5->back
	const char* t_skyPath[6] = {"resources/skybox/cloudtop_rf.tga", 
								"resources/skybox/cloudtop_lf.tga", 
								"resources/skybox/cloudtop_up.tga", 
								"resources/skybox/cloudtop_dn.tga",
								"resources/skybox/cloudtop_ft.tga",
								"resources/skybox/cloudtop_bk.tga"};
	scene->createSkybox(t_skyPath);
	m_mesh->setScale(0.25, 0.25, 0.25);

	while(window->isOpen()){
		window->processInput();
		
		window->clear(0.5f, 0.0f, 0.0f, 1.0f);

		m_light->processInput(window->getWindow());
		m_mesh->processInput(window->getWindow());
		m_light->getPosition();

		scene->draw();

    	window->swapBuffers();
		window->pollEvents();
	}
	scene->release();
	window->close();
	return 0;
}
