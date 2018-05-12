
#version 330

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec2 TexCoords;

uniform mat4 ViewProjection; // view-projection matrix
uniform mat4 modelMatrix; // model matrix
uniform mat3 normalMatrix; // normal matrix

uniform vec3 lightPosition; 
uniform vec3 cameraPostion;

// inputs for fragment shader
out vec3 normal;
out vec2 texcoord;
out vec3 directionToLight;
out vec3 directionToCamera;

void main(void){
   vec4 worldPos = modelMatrix * vec4(VertexPosition, 1.0);
   normal = normalMatrix * VertexNormal;
   texcoord = TexCoords;

   vec3 vectorToLight = lightPosition - worldPos.xyz;
   directionToLight = normalize( vectorToLight);
   directionToCamera = normalize( cameraPostion - worldPos.xyz );

   gl_Position = ViewProjection * worldPos; 
}
