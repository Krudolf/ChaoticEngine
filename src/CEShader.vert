#VERTEX SHADER LIGHTING MAPS
layout (location = 0) in vec4 VertexPosition;  #Vertex in local coords
layout (location = 1) in vec3 VertexNormal;    #Normal in local coords
layout (location = 2) in vec2 TextureCoords;   #Texture coords

out vec3 Position;    #Vertex in view coords
out vec3 Normal;      #Normal in view coords
out vec2 TexCoords;   #Texture coords

uniform mat4 ModelViewMatrix;
uniform mat4 NormalMatrix;
uniform mat4 MVP;

void main()
{
	#Transform vertex and normal into view coords
	Position = vec3 (ModelViewMatrix * VertexPosition);
	Normal = normalize (NormalMatrix * VertexNormal);

	#Texture coords stay the same
	TexCoords = TextureCoords;    

	#Transform and project the vertex (fragment position)
	gl_Position = MVP * VertexPosition;
} 