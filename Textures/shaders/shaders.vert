#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor; 
layout (location = 2) in vec2 uv;
out vec3 ourColor;      // Aqui ja cria uma variavel de 
                        // saida, não precisa criar no main
out float time2;

uniform float time;
uniform float scale;

void main()
{
   vec3 finalPos = aPos;
   
   finalPos.y += cos((time) + aPos.x) * scale;
   finalPos.x += sin((time) + aPos.x) * scale;

   gl_Position = vec4(aPos, 1.0);
   ourColor = aColor;
   time2 = time;
}
