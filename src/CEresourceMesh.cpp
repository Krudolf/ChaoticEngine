
#include <../include/CEresourceMesh.hpp>

//Constructor
CEResourceMesh::CEResourceMesh() : CEResource(){}


//Destructor
CEResourceMesh::~CEResourceMesh(){}

bool CEResourceMesh::loadFile(const char* p_name){
	Assimp::Importer importer;
	//| aiProcess_FlipUVs)
	//const aiScene* scene = importer.ReadFile(p_name, aiProcess_Triangulate | aiProcess_FlipUVs);
    const aiScene* scene = importer.ReadFile(p_name, aiProcess_Triangulate | aiProcess_GenNormals);

	if(!scene || scene->mFlags && AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return false;
	}

	m_directory = p_name.substr(0, p_name.find_last_of('/'));
	std::cout<<m_directory<<std::endl;

	processNode(scene->mRootNode, scene);
	return true;
}

void CEResourceMesh::processNode(aiNode* p_node, const aiScene* p_scene){
	// Process each mesh located at the current node
	for(GLuint i = 0; i < p_node->mNumMeshes; i++){
		// The node object only contains indices to index the actual objects in the scene. 
		// The scene contains all the data
		aiMesh* mesh = p_scene->mMeshes[p_node->mMeshes[i]];
		this->m_meshes.push_back(this->processMesh(mesh, p_scene));
		//processMesh(mesh, p_scene);
	}
	// then do the same for each of its children
    for(GLuint i = 0; i < p_node->mNumChildren; i++){
        this->processNode(p_node->mChildren[i], p_scene);
    }
}

CEsubMesh CEResourceMesh::processMesh(aiMesh* p_mesh, const aiScene* p_scene){
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

	// Return a mesh object created from the extracted mesh data
	return (CEsubMesh(vertices, indices));
}


void CEResourceMesh::draw(){

	for (GLuint i = 0; i < m_meshes.size(); i++) {
			m_meshes[i].subDraw();
	}
}


