#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor_; 
layout (location = 2) in vec2 aTexCoord;

out vec3 aColor;
out vec2 TexCoord;

uniform float time;
uniform vec2 resolution;

void main()
{
   vec3 FinalPos = aPos;
   //FinalPos = (resolution/resolution * 2.0) - 1.0;

   gl_Position = vec4(aPos, 1.0);
   aColor = aColor_;
   TexCoord = aTexCoord;
}
