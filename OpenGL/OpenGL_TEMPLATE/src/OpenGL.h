#ifndef OPENGL_H
#define OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class OpenGL {
private:
    GLFWwindow* window;
public:
    // Constructor and Destructor
    OpenGL();
    ~OpenGL();

    // Cicle
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput();

    bool InitializeGLFW();
    bool CreateWindow(int width, int height, const char* window_name);
    bool MakeContext();

    bool RunWindow(int width, int height, const char* window_name);


    // Functions
    GLFWwindow* GetWindow();
};

#endif //OPENGL_H