
#include <iostream>

#include <../include/CEresourceMesh.hpp>

//Constructor
CEResourceMesh::CEResourceMesh() : CEResource(){}

//Destructor
CEResourceMesh::~CEResourceMesh(){}

bool CEResourceMesh::loadFile(const char* p_name){

	Assimp::Importer importer;
	//| aiProcess_FlipUVs)
	const aiScene* scene = importer.ReadFile(p_name, aiProcess_Triangulate);

	if (!scene || scene->mFlags && AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return false;
	}

	processNode(scene->mRootNode, scene);
	return true;
}


void CEResourceMesh::processNode(aiNode * p_node, const aiScene * p_scene){

	// Process each mesh located at the current node
	for (GLuint i = 0; i < p_node->mNumMeshes; i++){
		// The node object only contains indices to index the actual objects in the scene. 
		// The scene contains all the data
		aiMesh* mesh = p_scene->mMeshes[p_node->mMeshes[i]];
		processMesh(mesh, p_scene);
	}
	// then do the same for each of its children
    for(GLuint i = 0; i < p_node->mNumChildren; i++)
    {
        processNode(p_node->mChildren[i], p_scene);
    }
}

void CEResourceMesh::processMesh(aiMesh * p_mesh, const aiScene * p_scene){

	// Data to fill
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	// Walk through each of the mesh's vertices
	for (GLuint i = 0; i < p_mesh->mNumVertices; i++)
	{
		Vertex vertex;
		glm::vec3 vector; 	//assimp dont uses vec3 class so we transfer the data first.
		// Positions
		vector.x = p_mesh->mVertices[i].x;
		vector.y = p_mesh->mVertices[i].y;
		vector.z = p_mesh->mVertices[i].z;
		vertex.Position = vector;
		// Normals
		vector.x = p_mesh->mNormals[i].x;
		vector.y = p_mesh->mNormals[i].y;
		vector.z = p_mesh->mNormals[i].z;
		vertex.Normal = vector;
		// Texture Coordinates
		if (p_mesh->mTextureCoords[0]) // Does the mesh contain texture coordinates?
		{
			glm::vec2 vec;
			// A vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
			// use models where a vertex can have multiple texture coordinates so we always take the first set (0).
			vec.x = p_mesh->mTextureCoords[0][i].x;
			vec.y = p_mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else{
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}
		vertices.push_back(vertex);
	}
	// Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (GLuint i = 0; i < p_mesh->mNumFaces; i++)
	{
		aiFace face = p_mesh->mFaces[i];
		// Retrieve all indices of the face and store them in the indices vector
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	// Save the information in the vectors form the resource
	m_vertices = vertices;
	m_indices = indices;
	m_nTriangles = p_mesh->mNumFaces;

}

void CEResourceMesh::prepareBuffers(){
	std::cout << "PETOO!!\n";

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);

	std::cout << "PETOO!!\n";
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, this->m_vertices.size() * sizeof(Vertex),
		&this->m_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(GLuint),
		&this->m_indices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)0);
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, Normal));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, TexCoords));

	glBindVertexArray(0);
}

void CEResourceMesh::draw(){
	prepareBuffers();

	// Draw mesh
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->m_indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


