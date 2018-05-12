
#version 330

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec2 TexCoords;

uniform mat4 MVP; // view-projection matrix
uniform mat4 ViewProjection; // view-projection matrix
uniform mat4 ModelMatrix; // model matrix
uniform mat3 NormalMatrix; // normal matrix

uniform vec3 lightPos;
uniform vec3 viewPos;

// inputs for fragment shader
out vec3 normal;
out vec2 texcoord;
out vec3 directionToLight;
out vec3 directionToCamera;

void main(void){
   vec4 worldPos = ModelMatrix * vec4(VertexPosition, 1.0);
   normal = NormalMatrix * VertexNormal;
   texcoord = TexCoords;

   vec3 vectorToLight = lightPos - worldPos.xyz;
   directionToLight = normalize( vectorToLight);
   directionToCamera = normalize( viewPos - worldPos.xyz );

   gl_Position = MVP * worldPos; 
}
