
#version 330 core
// Atributos
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec2 TextureCoords;

// Salida para el fragment

out vec3 Position; 
out vec3 Normal;
out vec2 TexCoords;

//uniform mat4 view;
//uniform mat4 model;
//uniform mat4 projection;
uniform mat4 ModelViewMatrix;
uniform mat4 MVP;

void main()
{
	mat3 NormalMatrix = mat3(transpose(inverse(model)));
    Position = vec3(model * view * vec4(VertexPosition, 1.0f));
    Normal = normalize(NormalMatrix * VertexNormal);

    gl_Position = model * view * projection * vec4(VertexPosition, 1.0f);
}