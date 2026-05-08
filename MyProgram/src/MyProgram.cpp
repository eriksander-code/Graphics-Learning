#include "MyProgram.h"

void MyProgram::Initialize() 
{    
    MyMesh.CreateMesh(MyVertex, sizeof(MyVertex), MyEBO, sizeof(MyEBO), 1, 1, 0, 0, 1);
    MyShader.CreateBasicShaders();
    MyTexture.BasicTexture(GL_TEXTURE0, GL_TEXTURE_2D, GL_NEAREST, "../assets/container.jpg", true, false);

    MyShader.Use();
    MyShader.setInt("texture0", 0);
}

void MyProgram::Processment() 
{
    MyClock.ProcessDelta();    
    if (MyTimer.Update(MyClock, 64.0f)) {
        glfwSetWindowTitle(GetWindowHandle(), TimerUI::GetFPSandMS(MyClock).c_str());    
    }
}

void MyProgram::Input(GLFWwindow* window, float Delta) 
{    
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_TRUE)
        glfwSetWindowShouldClose(window, true);
}

void MyProgram::Render() 
{
    MyShader.Use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, MyTexture.GetTextureID());

    glBindVertexArray(MyMesh.GetVAO());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
}

void MyProgram::Release() 
{
}