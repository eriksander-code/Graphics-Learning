#version 330 core

out vec4 FragColor;
in vec3 ourColor;
in vec3 ourPos;
in float time2;

void main() {

    vec3 finalColor = ourColor;
    finalColor.r += sin(((time2)*0.5));
    finalColor.g += sin(((time2)*0.5));
    finalColor.b += sin(((time2)*0.5));

    //finalColor.r += (sin(ourPos.x) + sin(((time2)*0.5)+0.5))/2;
    //finalColor.g += (cos(ourPos.y) + sin(((time2)*0.5)+0.5))/2;
    //finalColor.b += (sin(ourPos.y) + sin(((time2)*0.5)+0.5))/2;

    FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}