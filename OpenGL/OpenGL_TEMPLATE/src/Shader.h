#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader {
private:
    /////////////////////////////////////////////////////////////////////////////////
    // Shaders
    std::stringstream vertexShader; // Codigo
    const char* vShaderSource;
    unsigned int vShaderID;

    std::stringstream fragmentShader; // Codigo
    const char* fShaderSource;
    unsigned int fShaderID;

    std::stringstream shaderProgram; // Codigo
    unsigned int ShaderProgID;

    /////////////////////////////////////////////////////////////////////////////////
    // Status
    std::stringstream error;
    int success;
    char infoLog[512];
    
public:
    /////////////////////////////////////////////////////////////////////////////////
    // Constructor and destructor
    Shader();
    ~Shader();

    /////////////////////////////////////////////////////////////////////////////////
    // Functions
    void ProcessVertexShader(std::string path);
    void CompileVertexShader(const char* vertexShaderSourceCode);
    unsigned int GetVertexShaderID();
    std::string GetVertexShader();

    void ProcessFragmentShader(std::string path);
    void CompileFragmentShader(const char* fragmentShaderSourceCode);
    unsigned int GetFragmentShaderID();
    std::string GetFragmentShader();

    void AttachShaderProgram();
    void LinkShaderProgram();
    void ReleaseShaders();
    void Use();
    unsigned int GetShaderProgramID();
    std::string GetShaderProgram();

    void CreateBasicShaders(std::string path_vertex = "shaders/shaders.vert", std::string path_fragment = "shaders/shaders.frag");

    /////////////////////////////////////////////////////////////////////////////////
    // Status
    std::string GetError();
    int GetSuccessStatus();
    char* GetInfoLog();
};

#endif //SHADER_H