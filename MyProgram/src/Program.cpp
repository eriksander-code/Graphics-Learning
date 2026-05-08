#include "Program.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
} 

Program::Program() 
{
}

Program::~Program() 
{
}

void Program::Loop() {
    MyClock.StartCounter();
    InitializeEssential();
    Initialize();
    while (!glfwWindowShouldClose(MyOpenGL.GetWindow())) {
        ProcessEssential();
        Processment();
        Render();
        Essential();
    }
    Release();
}

void Program::Essential() {
    glfwSwapBuffers(MyOpenGL.GetWindow());   // SwapBuffer, nunca esqueça!
    glfwPollEvents();                   // Puxar Eventos, nunca esqueça!
}

void Program::ProcessEssential() {
    glClear(GL_COLOR_BUFFER_BIT);
    Input(MyOpenGL.GetWindow(), MyClock.GetDeltaTime());
}

void Program::InitializeEssential() 
{
    MyOpenGL.RunWindow(800, 600, "Window", OPGL_WINDOWED);
    glfwSetFramebufferSizeCallback(MyOpenGL.GetWindow(), framebuffer_size_callback);
}

void Program::Initialize() 
{    
}

void Program::Processment() 
{
}

void Program::Input(GLFWwindow* window, float Delta) 
{    
}

void Program::Render() 
{
}

void Program::Release() 
{
}

GLFWwindow* Program::GetWindowHandle() {
    return MyOpenGL.GetWindow();
};