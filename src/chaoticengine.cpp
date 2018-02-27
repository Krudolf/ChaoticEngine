
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
	GLenum err = glewInit();
	if(GLEW_OK != err){
	  fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	//prepare OpenGL surface for HSR
    glClearColor(0.3f, 0.3f, 0.3f, 0.f);
	glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar
}


void ChaoticEngine::createWindow(int p_width, int p_height, const char* p_title, bool fullscreen){
	m_window = new sf::RenderWindow(sf::VideoMode(p_width, p_height), p_title);

	initGL();
}

bool ChaoticEngine::isWindowOpen(){
	return m_window->isOpen();
}

sf::RenderWindow* ChaoticEngine::getWindow(){
	return m_window;
}

void ChaoticEngine::pushGLStates(){
	m_window->pushGLStates();
}

void ChaoticEngine::popGLStates(){
	m_window->popGLStates();
}

void ChaoticEngine::eventHandler(){
	sf::Event t_event;
	while(m_window->pollEvent(t_event)){
		switch(t_event.type){
			case sf::Event::Closed:
				m_window->close();
			break;
		}
    }
}

void ChaoticEngine::quad(){
	sf::RectangleShape quad(sf::Vector2f(250,100));
	quad.setFillColor(sf::Color::Red);

	m_window->draw(quad);
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
	//m_resourceManager->PONER_EL_METODO_DE_BORRADO_DE_MANU();

	delete m_resourceManager;
	delete m_root;
}

void ChaoticEngine::nodeMesh(){
	CETransform* 	trans1  = createTransform();
	CETransform* 	trans11 = createTransform();

	CEMesh*			mesh111 = createMesh();

	trans1 ->rotate(0, 45, 0);
	trans11->translate(200, 200, 200);

	CESceneNode* nodeTrans1  = createNode(getRootNode(), trans1);
	CESceneNode* nodeTrans11 = createNode(nodeTrans1, trans11);
	CESceneNode* nodeMesh111 = createNode(nodeTrans11, mesh111);
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

void ChaoticEngine::cube(){
	/*Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);*/
}

void ChaoticEngine::displayGL(){
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
	glColor3i(0,1,1);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f(-50.f,  50.f, -50.f);
	glVertex3f( 50.f,  50.f, -50.f);
	glVertex3f( 50.f, -50.f, -50.f);

	glColor3f(0,0,1);
	glVertex3f(-50.f, -50.f, 50.f);
	glVertex3f(-50.f,  50.f, 50.f);
	glVertex3f( 50.f,  50.f, 50.f);
	glVertex3f( 50.f, -50.f, 50.f);

	glColor3f(1,0,1);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f(-50.f,  50.f, -50.f);
	glVertex3f(-50.f,  50.f,  50.f);
	glVertex3f(-50.f, -50.f,  50.f);

	glColor3f(0,1,0);
	glVertex3f(50.f, -50.f, -50.f);
	glVertex3f(50.f,  50.f, -50.f);
	glVertex3f(50.f,  50.f,  50.f);
	glVertex3f(50.f, -50.f,  50.f);

	glColor3f(1,1,0);
	glVertex3f(-50.f, -50.f,  50.f);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f( 50.f, -50.f, -50.f);
	glVertex3f( 50.f, -50.f,  50.f);

	glColor3f(1,0,0);
	glVertex3f(-50.f, 50.f,  50.f);
	glVertex3f(-50.f, 50.f, -50.f);
	glVertex3f( 50.f, 50.f, -50.f);
	glVertex3f( 50.f, 50.f,  50.f);

	glEnd();
}