#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor_; 
layout (location = 2) in vec2 uv;

out vec3 aColor;

uniform float time;
uniform vec2 resolution;
uniform vec2 vel;

void main()
{
   vec3 FinalPos = aPos;
   //FinalPos = (resolution/resolution * 2.0) - 1.0;

   gl_Position = vec4(FinalPos.x+vel.x, FinalPos.y+vel.y, FinalPos.z,  1.0);
   aColor = aColor_;
}
