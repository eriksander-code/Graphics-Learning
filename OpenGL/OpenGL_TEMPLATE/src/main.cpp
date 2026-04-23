//////////////////////////////////////////////////////////////
// Includes and Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Timer.h"
#include "Clock.h"
#include "TimerUI.h"

#include "Shader.h"
#include "OpenGL.h"

//////////////////////////////////////////////////////////////
// VARIAVEIS E CONSTANTES GLOBAIS
Timer timer;
Clock myClock;
std::string title;

float vertex[] = {
    // first triangle
   1.0f, 1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   -1.0f, 1.0f, 0.0f,

   -1.0f, -1.0f, 0.0f,
   -1.0f, +1.0f, 0.0f,
   +1.0f, -1.0f, 0.0f,
};



//////////////////////////////////////////////////////////////
// FUNÇÔES
void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) 
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    
}

//////////////////////////////////////////////////////////////
// FUNÇÂO PRINCIPAL

int main(void) {

    OpenGL ogl;
    
    if (!ogl.RunWindow(800, 600, "Deu Certo!"))
        return 0;

    //////////////////////////////////////////////////////////////
    // Callback Functions
    glfwSetFramebufferSizeCallback(ogl.GetWindow(), framebuffer_size_callback);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //////////////////////////////////////////////////////////////
    // MESH    

    unsigned int VAO;
    unsigned int VBO;                

    glGenBuffers(1, &VBO);                
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);   
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);  
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    //////////////////////////////////////////////////////////////
    // SHADERS

    Shader shader;
    shader.CreateBasicShaders();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //////////////////////////////////////////////////////////////
    // LOOP

    myClock.StartCounter();
    while (!glfwWindowShouldClose(ogl.GetWindow())) {
        // Delta time
        myClock.ProcessDelta();
        if (timer.Update(myClock, 64.0f)) {

            title = TimerUI::GetFPSandMS(myClock);
            glfwSetWindowTitle(ogl.GetWindow(), title.c_str());
        }

        //////////////////////////////////////////////////////////////
        // RENDER

        glClear(GL_COLOR_BUFFER_BIT);  
        processInput(ogl.GetWindow());

        shader.Use();

        glUniform2f(glGetUniformLocation(shader.GetShaderProgramID(), "resolution"), 800, 600);


        glBindVertexArray(VAO);        
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // RENDER
        //////////////////////////////////////////////////////////////

        glfwSwapBuffers(ogl.GetWindow());       
        glfwPollEvents();              
    }

    glfwTerminate();

    return 0;
}