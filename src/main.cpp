
#include "include/main.hpp"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "include/ChaoticEngine/manager/stb_image.h"

int main(){    
	std::cout << "*************************\n* TEST DE CHAOTICENGINE *\n*************************" << std::endl; 
	CEWindow* m_window = new CEWindow(1024, 768, "3KSC", false); 
	CEScene*  m_scene  = new CEScene();

	float 		t_direction[]		= {-0.2f, -1.0f, -0.3f};
	float 		t_positionDirect[]	= {0.0, 0.0, 0.0};
	float 		t_position[]		= {0.0, 0.0, 0.0};
	float 		t_position2[] 		= {-50.0, 0.0, 0.0};
	float 		t_position3[] 		= {50.0, 0.0, 10.0};
	float 		t_position4[] 		= {0.0, 25.0, 0.0};
	float 		t_position5[] 		= {75.0, 50.0, 10.0};
	float 		t_lightAtenuation	= 1.0f;
	const char* t_skyboxPath[6]		= {
		"assets/skyboxes/fusfus_skybox/stratosphere_ft.tga",  
    	"assets/skyboxes/fusfus_skybox/stratosphere_bk.tga",  
    	"assets/skyboxes/fusfus_skybox/stratosphere_up.tga",  
    	"assets/skyboxes/fusfus_skybox/stratosphere_dn.tga", 
    	"assets/skyboxes/fusfus_skybox/stratosphere_rt.tga", 
    	"assets/skyboxes/fusfus_skybox/stratosphere_lf.tga"
	}; 

	CESceneCamera*			m_camera 	= m_scene->createCamera(true);
	CESceneLight*			m_lightDir	= m_scene->createDirectionalLight(t_direction, t_positionDirect);
	//CESceneLight*			m_light		= m_scene->createPointLight(t_lightAtenuation, t_position);
	//CESceneLight*			m_light2	= m_scene->createPointLight(t_lightAtenuation, t_position2);
	//CESceneLight*			m_light3	= m_scene->createPointLight(t_lightAtenuation, t_position3);
	//CESceneLight*			m_light4	= m_scene->createPointLight(t_lightAtenuation, t_position4);
	//CESceneLight*			m_light5	= m_scene->createPointLight(t_lightAtenuation, t_position5);
	//CESceneMesh*			m_mesh		= m_scene->createMesh("assets/sparky/sparky.obj");
	CESceneAnimation*		m_animation	= m_scene->createAnimatedMesh("assets/Anim/cubo_color.anim");
	m_animation->loadAnimation("assets/Anim/cubo_tam.anim");
	m_animation->changeCurrentAnimation(0);
	CESceneSkybox*			m_skybox	= m_scene->createSkybox(t_skyboxPath, 50);
	//CESceneParticleSystem* 	m_system	= m_scene->createParticleSystem("assets/awesome.bin", 50);
	//CESceneSprite*			m_sprite	= m_scene->createSprite("assets/awesome.bin", 10, 10);
	//CESceneBillboard*		m_billboard	= m_scene->createBillboard("assets/awesome.bin", 5, 2, m_mesh->getNode());
	
	while(m_window->isOpen()){ 
		m_window->processInput();
		m_window->clear(0.5f, 0.0f, 0.0f, 1.0f); 

		//m_mesh->processInput(m_window->getWindow());
		m_animation->processInput(m_window->getWindow());
		//std::cout << "Mesh:  " << m_mesh->getPosition().x << " , " << m_mesh->getPosition().y << " , " << m_mesh->getPosition().z << std::endl;
		//std::cout << "Light: " << m_light->getPosition().x << " , " << m_light->getPosition().y << " , " << m_light->getPosition().z << std::endl;
		//std::cout << m_camera->getPosition().x << " , " << m_camera->getPosition().y << " , " << m_camera->getPosition().z << std::endl;
		//m_system->update();

		m_scene->draw(); 

		m_window->swapBuffers(); 
		m_window->pollEvents(); 
	}

	m_scene->release(); 
	m_window->close(); 

	return 0; 
}
