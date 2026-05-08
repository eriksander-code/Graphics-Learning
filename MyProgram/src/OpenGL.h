#ifndef OPENGL_H
#define OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

constexpr int OPGL_BORDERLESS = 0;
constexpr int OPGL_FULLSCREEN = 1;
constexpr int OPGL_WINDOWED = 2;

class OpenGL {
private:
    // Objects
    GLFWwindow* window;
    GLFWmonitor* monitor;
    const GLFWvidmode* mode;

    // Attributes
    int windowWidth;
    int windowHeight;
    int frameBufferWidth;
    int frameBufferHeight;

public:
    // Constructor and Destructor
    OpenGL();
    ~OpenGL();

    // Cicle
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput();

    bool InitializeGLFW();
    bool CreateWindow(int width = 800, int height = 600, const char* window_name = "BasicWindow", int screen_mode = OPGL_WINDOWED);
    bool MakeContext();

    bool RunWindow(int width = 800, int height = 600, const char* window_name = "BasicWindow", int screen_mode = OPGL_WINDOWED);


    // Functions
    GLFWwindow* GetWindow();
    int GetWindowWidth();
    int GetWindowHeight();
    int GetFrameBufferWidth();
    int GetFrameBufferHeight();
    void GLFWConstructor();
    void WindowConstructor();
    void SetVSync(bool enabled);
};

#endif //OPENGL_H