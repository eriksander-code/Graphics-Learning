////////////////////////////////////////////////////////////////////////////
// Includes
#include <GLAD/glad.h>      // A ordem importa: glad -> glfw -> iostream -> demais
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

#include "Shader.h"
#include "Timer.h"
#include "Clock.h"
#include "TimerUI.h"
#include "OpenGL.h"
#include "Types.h"

////////////////////////////////////////////////////////////////////////////
// Global Variables and Constants
Clock MyClock;
Timer MyTimer;

struct vertex {
    f32 x,y,z;
    f32 r,g,b;
    f32 u,v;
};

vertex MyVertex[] {
    // X      Y      Z  |  R      G     B  |    U     V
    { 0.5f,  0.5f, 0.0f, 0.85f, 0.0f,  0.0f,  1.0f, 1.0f},  // top right
    { 0.5f, -0.5f, 0.0f, 0.0f,  0.85f, 0.0f,  1.0f, 0.0f}, // bottom right
    {-0.5f,  0.5f, 0.0f, 0.0f,  0.0f,  0.85f, 0.0f, 1.0f}, // top left 
    {-0.5f, -0.5f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f, 0.0f}, // bottom left
};

u32 EBOEnum[] {
    0, 1, 2,
    1, 2, 3
};


////////////////////////////////////////////////////////////////////////////
// Functions 

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}   // Não consegui inserir na classe OpenGL

void ProcessInput(GLFWwindow* window, float Delta) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

////////////////////////////////////////////////////////////////////////////
// Main function

int main() {
    
    ///////////////////////////////////////////////////////////////////////////////////////
    // Inicialização
    OpenGL ogl;
    // RunWIndow() é uma função que une os tres processos principais,
    // por motivos de aprendizado do pipeline, vou manter assim.
    
    if (!ogl.InitializeGLFW())                      // Inicializa recursos
        return -1;

    ogl.GLFWConstructor();
    
    if (!ogl.CreateWindow(800, 600, "Janela", OPGL_BORDERLESS))      // Cria janela
        return -1;

    ogl.WindowConstructor();
    
    if (!ogl.MakeContext())                         // Faz dela contexto atual
        return -1;

    ///////////////////////////////////////////////////////////////////////////////////////
    // Definições
    glfwSetFramebufferSizeCallback(ogl.GetWindow(), framebuffer_size_callback);
    //glClearColor(0.15f, 0.3f, 0.3f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    ///////////////////////////////////////////////////////////////////////////////////////
    // Buffers
    
    // Buffers ID
    GLuint VAO;     // GLuint e variaveis do opengl
    GLuint VBO;     // são mais apropriadas por
    GLuint EBO;     // pertencerem ao opengl.

    // Buffers
    glGenVertexArrays(1, &VAO);     // VAO -> genVertexArrays
    glBindVertexArray(VAO);         // VAO -> bindVertexArray
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(vertex), MyVertex, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex), (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex), (void*) (3*sizeof(f32)));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex), (void*) (6*sizeof(f32)));     // Fica inviavel contar bytes
        //                       ^ numero de componentes     ^ tamanho vertice      ^ Caminho até chegar no atribto                                     
        //                         dentro do atributo   
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(EBOEnum), EBOEnum, GL_STATIC_DRAW);
    glBindVertexArray(0);                       // Desativa VAO sempre primeiro
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    ///////////////////////////////////////////////////////////////////////////////////////
    // Shaders
    Shader shader;
    // Há função CreateBasics, por motivos de aprendizado
    // preferi expôr o esqueleto.

    shader.ProcessVertexShader("../shaders/shaders.vert");
    shader.CompileVertexShader(shader.GetVertexShader().c_str());

    shader.ProcessFragmentShader("../shaders/shaders.frag");
    shader.CompileFragmentShader(shader.GetFragmentShader().c_str());

    shader.AttachShaderProgram();
    shader.LinkShaderProgram();
    shader.ReleaseShaders();

    shader.setFloat("scale", 0.5f);

    ///////////////////////////////////////////////////////////////////////////////////////
    // Loop

    MyClock.StartCounter();         // Start no Relógio Delta
    while (!glfwWindowShouldClose(ogl.GetWindow())) {

        ///////////////////////////////////////////////////////////////////////////////////////
        // Processamento de Delta Time
        MyClock.ProcessDelta();     // Processa DeltaTime
        if (MyTimer.Update(MyClock, 64.0f)) {
            glfwSetWindowTitle(ogl.GetWindow(), TimerUI::GetFPSandMS(MyClock).c_str());     // Seta titulo, dá endereço da janela, e dá titulo  
                                                                                            // com TimerUI e GetFPSandMS().c_str().
        }

        ///////////////////////////////////////////////////////////////////////////////////////
        // Debug
        //std::cout << "Delta: " << MyClock.GetDeltaTime() << std::endl;

        ///////////////////////////////////////////////////////////////////////////////////////
        // Processamento
        glClear(GL_COLOR_BUFFER_BIT);
        ProcessInput(ogl.GetWindow(), MyClock.GetDeltaTime());

        shader.setFloat("time", glfwGetTime());

        ///////////////////////////////////////////////////////////////////////////////////////
        // Renderização no backbuffer
        shader.Use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);



        ///////////////////////////////////////////////////////////////////////////////////////
        // Exibição
        glfwSwapBuffers(ogl.GetWindow());   // SwapBuffer, nunca esqueça!
        glfwPollEvents();                   // Puxar Eventos, nunca esqueça!
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    return 0;
}

