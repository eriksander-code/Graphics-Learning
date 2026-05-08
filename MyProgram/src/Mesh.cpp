#include "Mesh.h"

/////////////////////////////////////////////////////////////////////////////////
// Constructor and Destructor

Mesh::Mesh() {
    NumberAttributes = 0;
};

Mesh::~Mesh() {

};

/////////////////////////////////////////////////////////////////////////////////
// Abstract

void Mesh::CreateMesh(vertex YourVertex[], size_t vertex_size, u32 ebo_array[], size_t size_ebo_array, bool position, bool color, bool color_alpha, bool normal, bool uv) 
{
    unsigned int counter = 0;

    StartVAORecording();
        CreateVBO(YourVertex, vertex_size);
        if (position == true) {
            SetAttrib(counter);
            counter = counter + 3;
        }

        if (color == true) {
            SetAttrib(counter);
            counter = counter + 3;
        }

        if (color_alpha == true) {
            SetAttrib(counter);
            counter = counter + 4;
        }
        
        if (normal == true) {
            SetAttrib(counter);
            counter = counter + 3;
        }

        if (uv == true) {
            SetAttrib(counter);
            counter = counter + 2;
        }
        CreateEBO(ebo_array, size_ebo_array);
    DeactiveBuffers();
}

/////////////////////////////////////////////////////////////////////////////////
// Start

void Mesh::StartVAORecording() {
    glGenVertexArrays(1, &VAO);     // VAO -> genVertexArrays
    glBindVertexArray(VAO);         // VAO -> bindVertexArray
}

void Mesh::CreateVBO(vertex YourVertex[], size_t vertex_size) {
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_size, YourVertex, GL_STATIC_DRAW);
}

void Mesh::CreateEBO(u32 ebo_array[], size_t size_ebo_array) {
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_ebo_array, ebo_array, GL_STATIC_DRAW);
}

/////////////////////////////////////////////////////////////////////////////////
// Config

void Mesh::SetAttrib(i32 offset_float_multiplier) {
    glVertexAttribPointer(NumberAttributes, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*) (offset_float_multiplier*sizeof(float)));
    glEnableVertexAttribArray(NumberAttributes);
    NumberAttributes = NumberAttributes + 1;
}

/////////////////////////////////////////////////////////////////////////////////
// Deletes

void Mesh::DeactiveBuffers() {
    glBindVertexArray(0);                       // Desativa VAO sempre primeiro
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::ReleaseBuffers() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

/////////////////////////////////////////////////////////////////////////////////
// Defaults
// unsigned int* Mesh::DefaultEBO() {
//     //return DefEBO;
// };

// // Tela toda
// Mesh::vertex* Mesh::DefaultVertex() {
//     //return DefVertex;      
// };

/////////////////////////////////////////////////////////////////////////////////
// Getters

GLuint Mesh::GetVAO() {
    return VAO;
}

i32 Mesh::GetNumberOfAttributes() {
    return NumberAttributes;
}