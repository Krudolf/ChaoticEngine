
#include <../include/CEresourceMesh.hpp>

//Constructor
CEResourceMesh::CEResourceMesh() : CEResource(){}


//Destructor
CEResourceMesh::~CEResourceMesh(){}

bool CEResourceMesh::loadFile(const char* p_name){
	Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(p_name, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if(!scene || scene->mFlags && AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return false;
	}

	std::string path = p_name;
	m_directory = path.substr(0, path.find_last_of('/'));
	std::cout << m_directory << std::endl;

	processNode(scene->mRootNode, scene);
	return true;
}

void CEResourceMesh::processNode(aiNode* p_node, const aiScene* p_scene){
	// Process each mesh located at the current node
	for(unsigned int i = 0; i < p_node->mNumMeshes; i++){
		// The node object only contains indices to index the actual objects in the scene. 
		// The scene contains all the data
		aiMesh* mesh = p_scene->mMeshes[p_node->mMeshes[i]];
		m_meshes.push_back(processMesh(mesh, p_scene));
	}
	// then do the same for each of its children
    for(unsigned int i = 0; i < p_node->mNumChildren; i++){
        processNode(p_node->mChildren[i], p_scene);
    }
}

CEsubMesh CEResourceMesh::processMesh(aiMesh* p_mesh, const aiScene* p_scene){
	// Data to fill
	std::vector<Vertex>  vertices;
	std::vector<GLuint>  indices;
	std::vector<Texture> textures;

	// Walk through each of the mesh's vertices
	for(unsigned int i = 0; i < p_mesh->mNumVertices; i++){
		Vertex vertex;
		glm::vec3 vector; 	//assimp dont uses vec3 class so we transfer the data first.
		// Positions
		if (p_mesh->HasPositions()) {
			vector.x = p_mesh->mVertices[i].x;
			vector.y = p_mesh->mVertices[i].y;
			vector.z = p_mesh->mVertices[i].z;
			vertex.Position = vector;
		}
		// Normals
		if(p_mesh->HasNormals()){
			vector.x = p_mesh->mNormals[i].x;
			vector.y = p_mesh->mNormals[i].y;
			vector.z = p_mesh->mNormals[i].z;
			vertex.Normal = vector;
		}

		// Texture Coordinates
		if(p_mesh->mTextureCoords[0]){
			glm::vec2 vec;
			vec.x = p_mesh->mTextureCoords[0][i].x;
			vec.y = p_mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}
	// Now wak through each of the mesh's faces
	for(unsigned int i = 0; i < p_mesh->mNumFaces; i++){
		aiFace face = p_mesh->mFaces[i];

		// Retrieve all indices of the face and store them in the indices vector
		for(unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	
	// Process materials
	if(p_mesh->mMaterialIndex >= 0){
		aiMaterial* material = p_scene->mMaterials[p_mesh->mMaterialIndex];
		// Same applies to other texture as the following list summarizes:
		// Diffuse: texture_diffuseN
		// Specular: texture_specularN

		// 1. diffuse maps
        vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        // 2. specular maps
        vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	// Return a mesh object created from the extracted mesh data
	return CEsubMesh(vertices, indices, textures);
}

void CEResourceMesh::draw(GLuint p_shaderProgram){
	for(GLuint i = 0; i < m_meshes.size(); i++){
			m_meshes[i].subDraw(p_shaderProgram);
	}
}

std::vector<Texture> CEResourceMesh::loadMaterialTextures(aiMaterial * p_mat, aiTextureType p_type, string p_typeName){
	vector<Texture> textures;
    for(unsigned int i = 0; i < p_mat->GetTextureCount(p_type); i++){
        aiString str;
        p_mat->GetTexture(p_type, i, &str);
        // check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
        bool skip = false;
        for(unsigned int j = 0; j < m_textures_loaded.size(); j++){
            if(std::strcmp(m_textures_loaded[j].path.data(), str.C_Str()) == 0){
                textures.push_back(m_textures_loaded[j]);
                skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
                break;
            }
        }
        if(!skip){   // if texture hasn't been loaded already, load it
            Texture texture;
            texture.id = TextureFromFile(str.C_Str(), m_directory);
            texture.type = p_typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            m_textures_loaded.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
        }
    }
	return textures;

}

GLint TextureFromFile(const char * p_path, std::string p_directory){
    string filename = string(p_path);
    filename = p_directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if(data){
        GLenum format;
        if(nrComponents == 1)
            format = GL_RED;
        else if(nrComponents == 3)
            format = GL_RGB;
        else if(nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else{
        std::cout << "Texture failed to load at path: " << p_path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

bool load_cube_map_side(GLuint texture, GLenum side_target, const char* file_name) {
  glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

  int x, y, n;
  int force_channels = 4;
  unsigned char*  image_data = stbi_load(file_name, &x, &y, &n, force_channels);
  if (!image_data) {
    fprintf(stderr, "ERROR: could not load %s\n", file_name);
    return false;
  }
  // non-power-of-2 dimensions check
  if ((x & (x - 1)) != 0 || (y & (y - 1)) != 0) {
    fprintf(stderr,
    	"WARNING: image %s is not power-of-2 dimensions\n",
    	file_name);
  }
  
  // copy image data into 'target' side of cube map
  glTexImage2D(side_target, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
  free(image_data);
  return true;
}