#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh {
private:
    std::vector<unsigned int> VAOs;
    std::vector<unsigned int> VBOs;

public:
    Mesh();
    ~Mesh();

    void AddVAO();      // VAO
    void AddVBO();      // VBO
    void AddObject();   // VBO e VAO
    void ActivateVAO();
    void ActivateVBO();
    void FillVBO();

};

#endif // MESH_H