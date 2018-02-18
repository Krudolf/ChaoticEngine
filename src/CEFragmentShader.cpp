#include <../include/CEFragmentShader.hpp>
/*
CEFragmentShader::CEFragmentShader(){}
CEFragmentShader::~CEFragmentShader(){}

// Calculate Phong's reflection model
vec3 CEFragmentShader::Phong () 
{
    // Calculate various vectors 
	vec3 n = normalize(Normal);
    vec3 s = normalize(Light.Position - Position);
	vec3 v = normalize(-Position);
	vec3 r = reflect(-s, n);

	// Ambient component
    vec3 Ambient = Light.Ambient * vec3(texture(Material.Diffuse, TexCoords));
  	
    // Diffuse component
    vec3 Diffuse = Light.Diffuse * max(dot(s, n), 0.0) * vec3(texture(Material.Diffuse, TexCoords));  
    
    // Specular component
    vec3 Specular = Light.Specular * pow(max(dot(r, v), 0.0), Material.Shininess) * vec3(texture(Material.Specular, TexCoords));
        
    return Ambient + Diffuse + Specular;  
} 

void CEFragmentShader::main()
{
	FragColor = vec3 (Phong(), 0.0);
}*/