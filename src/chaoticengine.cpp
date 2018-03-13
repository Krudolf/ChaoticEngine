
#include <iostream>

#include <../include/chaoticengine.hpp>
 

ChaoticEngine::ChaoticEngine(){
	m_root = new CESceneNode("root");

	m_resourceManager = new CEResourceManager();

	m_loader = new CEGLShader();
	m_shader = 0;
	m_vertex_path = "src/shader/CEShader.vert";
	m_fragment_path = "src/shader/CEShader.frag";
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
	
	glfwSetFramebufferSizeCallback(m_window, windows_size_callback);

	//glViewport(0, 0, p_width, p_height);
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
	glfwTerminate();
}
/*
	CALLBACKS
*/

void ChaoticEngine::windows_size_callback(GLFWwindow* p_window, int p_width, int p_height){
	glViewport(0, 0, p_width, p_height);
}

/*++++++++++++++++++++++*/

void ChaoticEngine::quad(){
	/*
	sf::RectangleShape quad(sf::Vector2f(250,100));
	quad.setFillColor(sf::Color::Red);

	m_window->draw(quad);
	*/
}

/*
			**************************************
			* FUNCTION FOR CREATE THE SCENE TREE *
			**************************************
*/

CESceneNode* ChaoticEngine::createNode(CESceneNode* p_father, CEEntity* p_entity){
	CESceneNode* t_node = new CESceneNode(p_father, "node");
	t_node->setEntity(p_entity);

	return t_node;
}

CETransform* ChaoticEngine::createTransform(){
	CETransform* t_transform = new CETransform();

	return t_transform;
}

CETransform* ChaoticEngine::translate(float p_tx, float p_ty, float p_tz){
    CETransform* t_transform = createTransform();
    t_transform->translate(p_tx, p_ty, p_tz);

	return t_transform;
}

CETransform* ChaoticEngine::rotate(float p_rx, float p_ry, float p_rz){
    CETransform* t_transform = createTransform();
    t_transform->rotate(p_rx, p_ry, p_rz);

	return t_transform;
}

CETransform* ChaoticEngine::scale(float p_sx, float p_sy, float p_sz){
    CETransform* t_transform = createTransform();
    t_transform->scale(p_sx, p_sy, p_sz);

	return t_transform;
}


CECamera* ChaoticEngine::createCamera(){
	CECamera* t_camera = new CECamera();

	return t_camera;
}

CELight* ChaoticEngine::createLight(glm::vec3 p_intensities, float p_attenuation){
	CELight* t_light = new CELight(p_intensities, p_attenuation);

	return t_light;
}

CEMesh* ChaoticEngine::createMesh(){
	CEMesh* t_mesh = new CEMesh();

	return t_mesh;
}

CESceneNode* ChaoticEngine::getRootNode(){
	return m_root;
}

void ChaoticEngine::draw(){
	m_root->draw();
}

void ChaoticEngine::release(){
	m_root->removeAllChilds();
	m_resourceManager->deleteResources();

	delete m_resourceManager;
	delete m_root;
}

void ChaoticEngine::nodeMesh(){
	CETransform* 	trans1  = rotate(0, 45, 0);
	CETransform* 	trans11 = translate(200, 200, 200);

	CEMesh*			mesh111 = createMesh();

	CESceneNode* nodeTrans1  = createNode(getRootNode(), trans1);
	CESceneNode* nodeTrans11 = createNode(nodeTrans1, trans11);
	CESceneNode* nodeMesh111 = createNode(nodeTrans11, mesh111);
}

void ChaoticEngine::loadModel(const char* p_path){
	CETransform* 	trans1  = createTransform();
	CETransform* 	trans11 = createTransform();

	CEMesh*			mesh111 = createMesh();

	trans1 ->rotate(0, 45, 0);
	trans11->translate(200, 200, 200);

	CESceneNode* nodeTrans1  = createNode(getRootNode(), trans1);
	CESceneNode* nodeTrans11 = createNode(nodeTrans1, trans11);
	CESceneNode* nodeMesh111 = createNode(nodeTrans11, mesh111);

	mesh111->loadResource(p_path);
}

// Loads the shaders. By default, loads default path. To change path, use setShadersPath(vertex_path, fragment_path)
void ChaoticEngine::loadShader(){
	m_shader = m_loader->LoadShader(m_vertex_path, m_fragment_path);
}

// Sets the path to load the shaders from
void ChaoticEngine::setShadersPath(const char* vert_path, const char* frag_path){
	m_vertex_path = vert_path;
	m_fragment_path = frag_path;
}

void ChaoticEngine::createVertexBuffer(){
	glm::vec3 Vertices[3];
    Vertices[0] = glm::vec3(-1.0f, -1.0f, 0.0f);
    Vertices[1] = glm::vec3(1.0f, -1.0f, 0.0f);
    Vertices[2] = glm::vec3(0.0f, 1.0f, 0.0f);

 	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

void ChaoticEngine::renderBuffers(){
	glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    //glfwSwapBuffers();
}

void ChaoticEngine::displayGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Apply some transformations for the cube
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -200.f);

	angle = m_clock.getElapsedTime().asSeconds();

	glRotatef(angle * 50, 1.f, 0.f, 0.f);
	glRotatef(angle * 30, 0.f, 1.f, 0.f);
	glRotatef(angle * 90, 0.f, 0.f, 1.f);

	//Draw a cube
	glBegin(GL_QUADS);//draw some squares
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f(-50.f,  50.f, -50.f);
	glVertex3f( 50.f,  50.f, -50.f);
	glVertex3f( 50.f, -50.f, -50.f);

	glVertex3f(-50.f, -50.f, 50.f);
	glVertex3f(-50.f,  50.f, 50.f);
	glVertex3f( 50.f,  50.f, 50.f);
	glVertex3f( 50.f, -50.f, 50.f);

	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f(-50.f,  50.f, -50.f);
	glVertex3f(-50.f,  50.f,  50.f);
	glVertex3f(-50.f, -50.f,  50.f);

	glVertex3f(50.f, -50.f, -50.f);
	glVertex3f(50.f,  50.f, -50.f);
	glVertex3f(50.f,  50.f,  50.f);
	glVertex3f(50.f, -50.f,  50.f);

	glVertex3f(-50.f, -50.f,  50.f);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f( 50.f, -50.f, -50.f);
	glVertex3f( 50.f, -50.f,  50.f);

	glVertex3f(-50.f, 50.f,  50.f);
	glVertex3f(-50.f, 50.f, -50.f);
	glVertex3f( 50.f, 50.f, -50.f);
	glVertex3f( 50.f, 50.f,  50.f);

	glEnd();
}