#ifndef CE_FRAGMENT_SHADER
#define CE_FRAGMENT_SHADER
/*
#include <glm.hpp>
#include <glew.h>
using namespace glm;

class CEFragmentShader{
public:
    CEFragmentShader();
	~CEFragmentShader();

  
    // OUT: communicate with pipeline
//    Layout (location = 0) out vec4 FragColor;	// Final fragment color

    // Struct to save materials
    struct TMaterial {
        glew::sampler2D Diffuse;
        sampler2D Specular;
        float     Shininess;
    };  

    // Struct to save lights
    struct TLight {
        vec3 Position;
        vec3 Ambient;
        vec3 Diffuse;
        vec3 Specular;
    };

    uniform TMaterial Material;
    uniform TLight Light;

    vec3 Phong ();
    void main();

private:
    // IN: coming from vertex shader
    in vec3 Position;  // Vertexes in view coordinates
    in vec3 Normal;    // Normal in view coordinates
    in vec2 TexCoords;
};
*/
#endif