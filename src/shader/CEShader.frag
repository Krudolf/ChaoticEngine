#version 330 core

out vec4 FragColor;

//Variable obtainet through the vertex shader
in  vec4 vertexColor;

//Variable obtained through the OpenGL program
uniform vec4 ourColor;

void main()
{
    //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    //FragColor = vertexColor;
    FragColor = ourColor;
}