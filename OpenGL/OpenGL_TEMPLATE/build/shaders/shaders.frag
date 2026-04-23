#version 330 core

out vec4 FragColor;

uniform vec2 resolution;

void main() {
   vec2 uv = gl_FragCoord.xy / resolution;

   vec2 c = (uv - 0.5) * 3.0;

   vec2 z = vec2(0.0);
   int i;
   int maxIter = 150;

   for(i = 0; i < maxIter; i++) {
      // z = z^2 + c
      z = vec2(
         z.x*z.x - z.y*z.y,
         2.0*z.x*z.y
      ) + c;

      if(length(z) > 2.0) break;
   }

   float color = float(i) / float(maxIter);
   FragColor = vec4(vec3(color), 1.0);
}