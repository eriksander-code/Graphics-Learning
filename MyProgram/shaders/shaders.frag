#version 330 core

in vec3 Color;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D texture0;     // inteiros
// informa qual unidade de textura o OpenGL deve usar 

uniform float alpha;

void main() {
    FragColor = texture(texture0, TexCoord);
}