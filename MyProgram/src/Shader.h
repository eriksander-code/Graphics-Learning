#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include "Types.h"

class Shader {
private:
    /////////////////////////////////////////////////////////////////////////////////
    // Shaders
    std::stringstream vertexShader; // Codigo
    const char* vShaderSource;
    u32 vShaderID;

    std::stringstream fragmentShader; // Codigo
    const char* fShaderSource;
    u32 fShaderID;

    std::stringstream shaderProgram; // Codigo
    u32 ShaderProgID;

    /////////////////////////////////////////////////////////////////////////////////
    // Uniforms
    std::map<const char*, GLint> UniformArray;

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
    u32 GetVertexShaderID();
    std::string GetVertexShader();

    void ProcessFragmentShader(std::string path);
    void CompileFragmentShader(const char* fragmentShaderSourceCode);
    u32 GetFragmentShaderID();
    std::string GetFragmentShader();

    void AttachShaderProgram();
    void LinkShaderProgram();
    void ReleaseShaders();
    void Use();
    u32 GetShaderProgramID();
    std::string GetShaderProgram();

    void CreateBasicShaders(std::string path_vertex = "../shaders/shaders.vert", std::string path_fragment = "../shaders/shaders.frag");

    /////////////////////////////////////////////////////////////////////////////////
    // Status
    std::string GetError();
    i32 GetSuccessStatus();
    char* GetInfoLog();

    /////////////////////////////////////////////////////////////////////////////////
    // Set Uniforms
    void setFloat(const char* name_var, float value);
    void setInt(const char* name_var, int value);
    void setBool(const char*  name_var, bool value);
    void setVec2Float(const char* name_var, float value_1, float value_2);
    void setVec3Float(const char* name_var, float value_1, float value_2, float value_3);
    void setVec4Float(const char* name_var, float value_1, float value_2, float value_3, float value_4);
    void setVec2Int(const char* name_var, int value_1, int value_2);
    void setVec3Int(const char* name_var, int value_1, int value_2, int value_3);
    void setVec4Int(const char* name_var, int value_1, int value_2, int value_3, int value_4);
};

#endif //SHADER_H