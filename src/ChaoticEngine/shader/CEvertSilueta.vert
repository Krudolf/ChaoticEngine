
#version 330

layout (location = 0) in vec3 VertexPosition;		
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec2 TextureCoords;

uniform mat4 ModelMatrix;
uniform mat4 MVP;

out vec3 world_pos;
out vec3 world_normal;
out vec2 TexCoords;

void main(){
	world_pos = mat3(ModelMatrix) * VertexPosition;
	world_normal = normalize(mat3(ModelMatrix) * VertexNormal);
	TexCoords = TextureCoords;

	gl_Position =MVP * vec4(VertexPosition,1); 
}
