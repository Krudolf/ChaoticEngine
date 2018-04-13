
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

#include <../include/chaoticengine.hpp>

void showMatrix(glm::mat4 p_matrix){   
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


ChaoticEngine::ChaoticEngine(){
	m_root = new CESceneNode("root");

	m_resourceManager = new CEResourceManager();

	m_loader = new CEGLShader();
	m_shaderProgram = 0;
	m_vertex_path = "src/shader/CEShader.vert";
	m_fragment_path = "src/shader/CEShader.frag";
	
	m_VBO = 0;
	m_VAO = 0;
	m_EBO = 0;
}

ChaoticEngine::~ChaoticEngine(){}

void ChaoticEngine::initGL(){
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void ChaoticEngine::createWindow(int p_width, int p_height, const char* p_title, bool fullscreen){
	initGL();
	
	m_window = glfwCreateWindow(p_width, p_height, p_title, NULL, NULL);
	if (m_window == NULL){
	    std::cout << "Failed to create GLFW window" << std::endl;
	    glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);
	
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if(GLEW_OK != err){
		//Problem: glewInit failed, something is seriously wrong.
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	//fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	glfwSetFramebufferSizeCallback(m_window, windows_size_callback);

	std::cout << "VERSION OPENGL: " << glGetString(GL_VERSION) << std::endl;

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
}

bool ChaoticEngine::isWindowOpen(){
	if(glfwWindowShouldClose(m_window) == GL_FALSE)
		return true;
	
	return false;
}

void ChaoticEngine::closeWindow(){
	glfwDestroyWindow(m_window);
}

void ChaoticEngine::clearWindow(float p_red, float p_green, float p_blue, float p_alpha){
	glClearColor(p_red, p_green, p_blue, p_alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

GLFWwindow* ChaoticEngine::getWindow(){
	return m_window;
}

void ChaoticEngine::swapBuffers(){
	glfwSwapBuffers(m_window);
}

void ChaoticEngine::pollEvents(){
	glfwPollEvents();
}

void ChaoticEngine::processInput(){
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}

void ChaoticEngine::terminate(){
	glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);

	glfwTerminate();
}

void ChaoticEngine::createTriangle(){
	float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    uint indices[] = {  // note that we start from 0!
        0, 3, 1,  // first Triangle
        1, 3, 2   // second Triangle
    };
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * 6, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 
}

void ChaoticEngine::drawTriangle(){
	/*float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(m_shaderProgram, "ourColor");
	//glUseProgram(m_shaderProgram);
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);*/

	glBindVertexArray(m_VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0); //no need to unbind it every time 
}

/*
	CALLBACKS
*/
void ChaoticEngine::windows_size_callback(GLFWwindow* p_window, int p_width, int p_height){
	glViewport(0, 0, p_width, p_height);
}


//			*****************************************************************************
//			* 					FUNCTION FOR CREATE THE SCENE TREE 						*
//			*****************************************************************************


CESceneNode* ChaoticEngine::createNode(CEEntity* p_entity, CESceneNode* p_father){
	if(p_father == NULL)
		p_father = getRootNode();

	CESceneNode* t_node = new CESceneNode(p_father, "node");
	t_node->setEntity(p_entity);

	return t_node;
}

CETransform* ChaoticEngine::newTransform(){
	CETransform* t_transform = new CETransform();

	return t_transform;
}

CETransform* ChaoticEngine::translate(float p_tx, float p_ty, float p_tz){
    CETransform* t_transform = newTransform();
    t_transform->translate(p_tx, p_ty, p_tz);

	return t_transform;
}

CETransform* ChaoticEngine::rotate(float p_rx, float p_ry, float p_rz){
    CETransform* t_transform = newTransform();
    t_transform->rotate(p_rx, p_ry, p_rz);

	return t_transform;
}

CETransform* ChaoticEngine::scale(float p_sx, float p_sy, float p_sz){
    CETransform* t_transform = newTransform();
    t_transform->scale(p_sx, p_sy, p_sz);

	return t_transform;
}

CECamera* ChaoticEngine::newCamera(){
	CECamera* t_camera = new CECamera();

	return t_camera;
}

CELight* ChaoticEngine::newLight(glm::vec3 p_intensities, float p_attenuation){
	CELight* t_light = new CELight(p_intensities, p_attenuation);

	return t_light;
}

CEMesh* ChaoticEngine::newMesh(){
	CEMesh* t_mesh = new CEMesh(m_shaderProgram);

	return t_mesh;
}

CESceneNode* ChaoticEngine::getRootNode(){
	return m_root;
}

void ChaoticEngine::draw(){
	m_root->draw();
}

void ChaoticEngine::release(){
	terminate();

	m_root->removeAllChilds();
	m_resourceManager->deleteResources();

	delete m_resourceManager;
	delete m_root;
}

// Sets the path to load the shaders from
void ChaoticEngine::setShadersPath(const char* vert_path, const char* frag_path){
	m_vertex_path = vert_path;
	m_fragment_path = frag_path;
}

// Loads the shaders. By default, loads default path. To change path, use setShadersPath(vertex_path, fragment_path)
GLuint ChaoticEngine::loadShader(){
	m_shaderProgram = m_loader->LoadShader(m_vertex_path, m_fragment_path);
	return m_shaderProgram;
}

void ChaoticEngine::createCube(){
	CETransform* 	t_rotate    = rotate(0.0, 0.0, 0.0);
	CETransform* 	t_translate = translate(0.0, 0.0, 0.0);

	CEMesh*			t_mesh 		= newMesh();

	CESceneNode* nodeRotate  	= createNode(t_rotate , getRootNode());
	CESceneNode* nodeTranslate 	= createNode(t_translate, nodeRotate);
	CESceneNode* nodeMesh 		= createNode(t_mesh, nodeTranslate);

	t_mesh->loadResource("resources_prueba/life_tank.obj");
}

void ChaoticEngine::createMesh(){
	CETransform* 	trans1  = rotate(0, 45, 0);
	CETransform* 	trans11 = translate(200, 200, 200);

	CEMesh*			mesh111 = newMesh();

	CESceneNode* nodeTrans1  = createNode(trans1 , getRootNode());
	CESceneNode* nodeTrans11 = createNode(trans11, nodeTrans1);
	CESceneNode* nodeMesh111 = createNode(mesh111, nodeTrans11);
}

CESceneNode* ChaoticEngine::loadModel(const char* p_path){
	CETransform* 	t_scale     = scale(0.25, 0.25, 0.25);
	CETransform* 	t_rotate    = rotate(0.0, 0.0, 0.0);
	CETransform* 	t_translate = translate(0.0, 0.0, 0.0);

	CEMesh*			t_mesh 		= newMesh();

	CESceneNode* nodeScale  	= createNode(t_scale, getRootNode());
	CESceneNode* nodeRotate  	= createNode(t_rotate, nodeScale);
	CESceneNode* nodeTranslate 	= createNode(t_translate, nodeRotate);
	CESceneNode* nodeMesh 		= createNode(t_mesh, nodeTranslate);

	t_mesh->loadResource(p_path);
	
	return nodeMesh;
}

//*******************************************************************
//* 							LIGHTS 								*
//*******************************************************************
CESceneNode* ChaoticEngine::createLight(glm::vec3 p_intensities, float p_attenuation, bool p_setActive){
	CETransform* 	t_rotate    = rotate(0.0, 0.0, 0.0);
	CETransform* 	t_translate = translate(0.0, 0.0, 0.0);

	CELight*		t_light 	= newLight(p_intensities, p_attenuation);

	CESceneNode* nodeRotate  	= createNode(t_rotate , getRootNode());
	CESceneNode* nodeTranslate 	= createNode(t_translate, nodeRotate);
	CESceneNode* nodeLight 		= createNode(t_light, nodeTranslate);

	if(p_setActive)
		setActiveLight(nodeLight);

	return nodeLight;
}

void ChaoticEngine::setActiveLight(CESceneNode* p_nodeLight){
	m_activeLights.push_back(p_nodeLight);
	getLightMatrix();
}

void ChaoticEngine::getLightMatrix(){
	//Look the vector of active lights
	for(int i = 0; i < m_activeLights.size(); i++){
		glm::mat4 m_tempMatrix;
		CESceneNode* t_node = m_activeLights.at(i)->getFather();
		//Go through all the transforms until we reach the root
		while(t_node != NULL){
			if(dynamic_cast<CETransform*>(t_node->getEntity())){
				CETransform* t_tempTransform = (CETransform*)t_node->getEntity();
				m_matrixStack.push(t_tempTransform->getMatrix());
			}
			t_node = t_node->getFather();
		}
		//Calculate the lightmatrix
		while(!m_matrixStack.empty()){
			m_tempMatrix = m_tempMatrix * m_matrixStack.top();
			m_matrixStack.pop();
		}
		m_lightMatrix = m_lightMatrix * m_tempMatrix;
		std::cout << "LIGHT MATRIX!" << std::endl;
		showMatrix(m_lightMatrix);
	}
}


//*******************************************************************
//* 						   CAMERAS 								*
//*******************************************************************
CESceneNode* ChaoticEngine::createCamera(bool p_setActive){
	CETransform* 	t_rotate    = rotate(0.0, 0.0, 0.0);
	CETransform* 	t_translate = translate(0.0, 0.0, 2.0);

	CECamera*		t_camera 	= newCamera();

	CESceneNode* nodeRotate  	= createNode(t_rotate , getRootNode());
	CESceneNode* nodeTranslate 	= createNode(t_translate, nodeRotate);
	CESceneNode* nodeCamera		= createNode(t_camera, nodeTranslate);

	if(p_setActive)
		setActiveCamera(nodeCamera);

	return nodeCamera;
}

void ChaoticEngine::setActiveCamera(CESceneNode* p_nodeCamera){
	m_activeCamera = p_nodeCamera;
	CECamera* t_cameraNode = static_cast<CECamera*>(p_nodeCamera->getEntity());
	t_cameraNode->setProjectionMatrix();
	t_cameraNode->setViewMatrix(getViewMatrix());
}

glm::mat4 ChaoticEngine::getViewMatrix(){
	glm::mat4 m_tempMatrix;
	CESceneNode* t_node = m_activeCamera->getFather();
	//Go through all the transforms until we reach the root
	while(t_node != NULL){
		if(dynamic_cast<CETransform*>(t_node->getEntity())){
			CETransform* t_tempTransform = (CETransform*)t_node->getEntity();
			m_matrixStack.push(t_tempTransform->getMatrix());
		}
		t_node = t_node->getFather();
	}
	//Calculate the lightmatrix
	while(!m_matrixStack.empty()){
		m_tempMatrix = m_tempMatrix * m_matrixStack.top();
		m_matrixStack.pop();
	}
	m_tempMatrix = glm::inverse(m_tempMatrix);
	return m_tempMatrix;
}