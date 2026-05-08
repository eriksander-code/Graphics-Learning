#ifndef PROGRAM_H
#define PROGRAM_H

#include <GLAD/glad.h>   
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "Shader.h"
#include "Timer.h"
#include "Clock.h"
#include "TimerUI.h"
#include "OpenGL.h"
#include "Types.h"
#include "Mesh.h"
#include "Textures.h"

class Program {
private:
    // Objects
    OpenGL MyOpenGL;

public:
    Mesh MyMesh;
    Texture MyTexture;
    Shader MyShader;
    Clock MyClock;
    Timer MyTimer;

    Program();
    ~Program();

    void Loop();
    void InitializeEssential();
    void Essential();
    void ProcessEssential();
    virtual void Input(GLFWwindow* window, float Delta);
    virtual void Initialize();
    virtual void Processment();
    virtual void Render();
    virtual void Release();

    GLFWwindow* GetWindowHandle();
};

#endif //PROGRAM_H