
#version 330

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;

uniform mat4	MVP;
uniform float	offset;	//Offset along normal

void main(){
	vec4 pos	= vec4(VertexPosition + VertexNormal * offset, 1.0);
	gl_Position	= MVP * pos;
}