#include "OpenGL.h"

OpenGL::OpenGL()
{

}
OpenGL::~OpenGL()
{

}

// Cicle
void OpenGL::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void OpenGL::processInput() 
{

};

bool OpenGL::InitializeGLFW() {
    // Inicializando GLFW:
    if (!glfwInit()) {                                              // Verifica inicialização
        std::cout << "Failed to Initialize GLFW." << std::endl;
        return 0; 
    }                                     
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // define como versão maxima 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  // define como versão minima 3 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // define escopo de funcoes que vamos usar
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE)           // compatibilidade com MacOS

    return 1;
}

bool OpenGL::CreateWindow(int width, int height, const char* window_name) {
    std::cout << "Creating window..." << std::endl;
    window = glfwCreateWindow(width, height, window_name, NULL, NULL);
    if (window == NULL) 
    {
        std::cout << "Failed to Create GLFW window." << std::endl;
        glfwTerminate();    // Finaliza GLFW
        return 0;
    }
    return 1;
}

bool OpenGL::MakeContext() {
    glfwMakeContextCurrent(window);     // diz para GLFW fazer o contexto
                                        // da nossa janela como o principal
                                        // do nosso processo (thread)

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD." << std::endl;
        return -1;
    }
    return 1;
}

bool OpenGL::RunWindow(int width, int height, const char* window_name) {
    if (!InitializeGLFW())
        return 0;
    
    if (!CreateWindow(width, height, window_name))
        return 0;

    if (!MakeContext())
        return 0;
    
    return 1;
}



GLFWwindow* OpenGL::GetWindow() {
    return window;
}
