
#include <../include/CEresourceTexture.hpp>
#include <iostream>

//Constructor
CEResourceTexture::CEResourceTexture() : CEResource(){}


//Destructor
CEResourceTexture::~CEResourceTexture(){}

bool CEResourceTexture::loadFile(const char* p_name){
    m_textureId = TextureFromFile(p_name);
    if(m_textureId == 0)
        return false;

    return true;
}

void CEResourceTexture::draw(GLuint p_shaderProgram){
}


GLint CEResourceTexture::TextureFromFile(const char * p_path){

    std::string t_filename = p_path;
    std::string t_directory = t_filename.substr(0, t_filename.find_last_of('/'));

    t_filename = t_directory + '/' + t_filename;

    unsigned int textureID = 0;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(t_filename.c_str(), &width, &height, &nrComponents, 0);
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