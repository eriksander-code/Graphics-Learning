#ifndef MYPROGRAM_H
#define MYPROGRAM_H

#include "Program.h"

class MyProgram : public Program {
private:
    // Vertex
    u32 MyEBO[6] {
        0, 1, 2,
        1, 2, 3
    };

    // Default Vertex
    Mesh::vertex MyVertex[4] {         // Padrão
        // X      Y      Z  |  R      G     B  |    U     V
        { 0.5f,  0.5f, 0.0f, 0.85f, 0.0f,  0.0f,  1.0f, 1.0f},  // top right
        { 0.5f, -0.5f, 0.0f, 0.0f,  0.85f, 0.0f,  1.0f, 0.0f}, // bottom right
        {-0.5f,  0.5f, 0.0f, 0.0f,  0.0f,  0.85f, 0.0f, 1.0f}, // top left 
        {-0.5f, -0.5f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f, 0.0f}, // bottom left
    };


public:

    void Input(GLFWwindow* window, float Delta);
    void Initialize();
    void Processment();
    void Render();
    void Release();
};


#endif //MYPROGRAM_H