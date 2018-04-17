
#version 420 core

//Entrada desde el vertex shader
in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;  

//Salida para el Pipeline
out vec4 FragColor;

//Estructura para guardar la textura. Se guardan las propiedades difusas y especulares de la textura
struct TMaterial{
	sampler2D Diffuse;
	sampler2D Specular;
	float Shininess;
};

//Estructura para guardar las luces: Posicion y propiedades; ambiental, difusa y especular
struct TLight{
	vec3 Position;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
};

//Estado de OpenGL: textura y luz de los tipos anteriores
uniform TMaterial Material;
uniform TLight Light;

//Funcion para calculo de reflexion de Phong
vec3 Phong(){

	//calculo de vectores
	vec3 n = normalize (Normal);
	vec3 s = normalize (Light.Position - Position);
	vec3 v = normalize (-Position);
	vec3 r = reflect (-s, n);

	//Componente ambiental
	//vec3 Ambient = Light.Ambient * vec3(texture(Material.Diffuse, TexCoords));
	//Componente difusa
	//vec3 Diffuse = Light.Diffuse * max(dot(s, n), 0.0) * vec3(texture(Material.Diffuse, TexCoords));
	//Componente especular
	//vec3 Specular = Light.Specular * pow(max(dot(r, v), 0.0), Material.Shininess) * vec3(texture(Material.Specular, TexCoords));

	vec3 Ambient = Light.Ambient * vec3(0.2,0.2,0.2);
	vec3 Diffuse = Light.Diffuse * max(dot(s, n), 0.0) * vec3(0.5,0.5,0.5);
	vec3 Specular = Light.Specular * pow(max(dot(r, v), 0.0), 16.0f) * vec3(0.7,0.7,0.7);

	return Ambient + Diffuse + Specular;
}

void main(){
	
	FragColor = vec4 (Phong(), 0.0);
}