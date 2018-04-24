 
#ifndef CERESOURCETEXTURE
#define CERESOURCETEXTURE

#include "stb_image.h"
#include <glew.h> 
#include <glm.hpp>
#include <string>

#include "manager/CEresource.hpp"


class CEResourceTexture: public CEResource{
public:
	CEResourceTexture();
	~CEResourceTexture();

	bool loadFile(const char* p_name);
	void draw(GLuint p_shaderProgram);

	GLint getTextureId(){return m_textureId;}

	unsigned char* getTextureData(){return m_textureData;}

	std::string getTextureType(){return m_type;}
	void setTextureType(std::string p_type){m_type = p_type;}

	std::string getTexturePath(){return m_path;}
	void setTexturePath(std::string p_path){m_path = p_path;}

	void glBuffersTexture();

private:

	GLint m_textureId;
    std::string m_type;
    std::string m_path;
    int m_width, m_height, m_nrComponents;
    unsigned char* m_textureData;
	bool textureFromFile(const char* p_path);
};

#endif