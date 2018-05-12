
#version 330

uniform sampler2D	colorTexture;	//diffuse texture
uniform float		numShades;		//number of shades

// inputs from vertex shader
in vec3 normal;
in vec2 texcoord;
in vec3 directionToLight;
in vec3 directionToCamera;

layout (location = 0) out vec4 FragColor;

// calculate diffuse component of lighting
float diffuseSimple(vec3 L, vec3 N){
	return clamp(dot(L, N), 0.0, 1.0);
}

// calculate specular component of lighting
float specularSimple(vec3 L,vec3 N,vec3 H){
	if(dot(N,L) > 0){
		return pow(clamp(dot(H, N), 0.0, 1.0), 64.0);
	}
	return 0.0;
}

void main(void){
   vec3 baseColor = vec3(1.0f,1.0f,1.0f);
   // sample color from diffuse texture
   vec3 colfromtex = texture(colorTexture, texcoord).rgb;

   // calculate total intensity of lighting
   vec3 halfVector = normalize( directionToLight + directionToCamera );
   float iambi = 0.1;
   float idiff = diffuseSimple(directionToLight, normal);
   float ispec = specularSimple(directionToLight, normal, halfVector);
   float intensity = iambi + idiff + ispec;

   // quantize intensity for cel shading
   float shadeIntensity = ceil(intensity * numShades) / numShades;

   // or use color from texture
   FragColor.xyz = colfromtex * shadeIntensity ;

   FragColor.w = 1.0;
}