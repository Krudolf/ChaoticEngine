#include <../include/CEcamera.hpp>

#include <iomanip>
#include <iostream>

void showMat(glm::mat4 p_matrix){   
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << p_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Por defecto crea una camara con perspectiva
CECamera::CECamera() : CEEntity(){
	//setParallel(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	setPerspective(90.0f, 1.0f, 0.1f, 100.0f);
}

CECamera::~CECamera(){}

void CECamera::setPerspective(float p_angle, float p_aspect, float p_near, float p_far){
	m_isPerspective = true;
	m_angle	 		= p_angle;
	m_aspect 		= p_aspect;
	m_near	 		= p_near;
	m_far 	 		= p_far;
	m_projection 	= glm::perspective(m_angle, m_aspect, m_near, m_far);
}

void CECamera::setParallel(float p_left, float p_right, float p_bottom, float p_top, float p_near, float p_far){
	m_isPerspective = false;
	m_left 	 		= p_left;
	m_right  		= p_right;
	m_bottom 		= p_bottom;
	m_top 	 		= p_top;
	m_near	 		= p_near;
	m_far 	 		= p_far;
	m_projection 	= glm::ortho(m_left, m_right, m_bottom, m_top, m_near, m_far);
	m_tarjet 		= glm::vec3(0,0,0);
}

void CECamera::setTarjet(float p_x, float p_y, float p_z){
	m_tarjet = glm::vec3(p_x, p_y, p_z);
}

void CECamera::setTarjet(glm::vec3 p_tarjet){
	m_tarjet = p_tarjet;
}

glm::mat4 CECamera::getMatrix(){
	return m_projection;
}

void CECamera::setProjectionMatrix(){
	m_projectionMatrix = m_projection;
	//std::cout << "PROJECTION:" << std::endl;
	//showMat(m_projectionMatrix);
}

void CECamera::setViewMatrix(glm::mat4 p_viewMatrix){
	if(m_isPerspective){
		glm::mat4 t_tempMatrix = glm::inverse(p_viewMatrix);
		glm::vec3 t_pos = (glm::vec3)t_tempMatrix[3];
		//			   glm::lookAt(eye	, tarjet  , up				);
		m_viewMatrix = glm::lookAt(t_pos, m_tarjet, glm::vec3(0,1,0));
	}
	else
		m_viewMatrix = p_viewMatrix;
	//std::cout << "VIEW:" << std::endl;
	//showMat(m_viewMatrix);
}

void CECamera::beginDraw(){}

void CECamera::endDraw(){}
