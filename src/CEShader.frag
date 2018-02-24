// OUT: communicate with pipeline
Layout (location = 0) out vec4 FragColor;	// Final fragment color

// IN: coming from vertex shader
in vec3 Position;  // Vertexes in view coordinates
in vec3 Normal;    // Normal in view coordinates
in vec2 TexCoords;

// Struct to save materials
struct TMaterial {
    glew::sampler2D Diffuse;
    sampler2D Specular;
    float     Shininess;
};  

// Struct to save lights
struct TLight {
    vec3 Position;
    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;
};

uniform TMaterial Material;
uniform TLight Light;

// Calculate Phong's reflection model
vec3 Phong () 
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

void main()
{
	FragColor = vec3 (Phong(), 0.0);
}
