
#version 330

layout(location = 0) out vec4 out_color;

struct TMaterial{
	float Shininess;
};

uniform sampler2D colorTexture;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform TMaterial 	Material;

uniform int texture_diffuse;
uniform int texture_specular;

const vec3 ambinet = vec3(0.90, 0.0, 0.20);
//const vec3 Kd = vec3(0.30,0.80,0.10);

in vec3 world_pos;
in vec3 world_normal;
in vec2 TexCoords;

const int levels = 5;
const float scaleFactor = 1.0 / levels;

void main(){
	vec3 color= texture(colorTexture, TexCoords).rgb;

	vec3 Kd = vec3(0.30,0.80,0.10);
	
	vec3 L = normalize(lightPos - world_pos);
	vec3 V = normalize(viewPos - world_pos);

	float difuza = max(0, dot(L,world_normal));
	Kd = Kd * texture_diffuse* floor(difuza * levels) * scaleFactor;

	vec3 H = normalize(L + V);

	float speculara = 0;

	if(dot(L,world_normal) > 0.0){
        speculara = texture_specular * pow( max(0, dot( H, world_normal)), Material.Shininess);
	}	
	
	float specMask = (pow(dot(H, world_normal), Material.Shininess) > 0.4) ? 1 : 0;
	float edgeMask = (dot(V, world_normal) >  0.2) ? 1 : 0;
	
	color = edgeMask * (color + Kd + speculara * specMask);

	out_color = vec4(color,1);
}