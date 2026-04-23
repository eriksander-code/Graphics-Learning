#include "Shader.h"

Shader::Shader() 
{
    
}

Shader::~Shader() 
{
    glDeleteProgram(ShaderProgID);
    ReleaseShaders();
}

void Shader::CreateBasicShaders(std::string path_vertex, std::string path_fragment) {
    ProcessVertexShader(path_vertex);
        std::string vertexShaderSource = GetVertexShader();
        const char* vShader = vertexShaderSource.c_str();
    CompileVertexShader(vShader);

    ProcessFragmentShader(path_fragment);
        std::string fragmentShaderSource = GetFragmentShader();  
        const char* fShader = fragmentShaderSource.c_str();
    CompileFragmentShader(fShader);

    AttachShaderProgram();
    LinkShaderProgram();
    ReleaseShaders();
}

void Shader::ProcessVertexShader(std::string path) 
{
    vertexShader.str("");
    vertexShader.clear();

    std::ifstream file;

    file.open(path);
        if (file.is_open()) {
            vertexShader << file.rdbuf();
            std::cout << "VERTEX SHADER: TRUE.";

        } else {
            std::cout << "VERTEX SHADER: Could not open archive.";
        }
    file.close(); 
}

void Shader::CompileVertexShader(const char* vertexShaderSourceCode) {
    // vertex Shader
    vShaderID = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vShaderID, 1, &vertexShaderSourceCode, NULL);
    glCompileShader(vShaderID);

    glGetShaderiv(vShaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vShaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::ProcessFragmentShader(std::string path) 
{
    fragmentShader.str("");
    fragmentShader.clear();

    std::ifstream file;

    file.open(path);
        if (file.is_open()) {
            fragmentShader  << file.rdbuf();
            std::cout << "FRAGMENT SHADER: TRUE.";

        } else {
            std::cout << "FRAGMENT SHADER: Could not open archive.";
        }
    file.close(); 
}

void Shader::CompileFragmentShader(const char* fragmentShaderSourceCode) {
    // Fragment shader 
    // relacionado a saida de cores do vertex
    
    fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShaderID, 1, &fragmentShaderSourceCode, NULL);
    glCompileShader(fShaderID);

    glGetShaderiv(fShaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fShaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::AttachShaderProgram() {
    // shader programs
    ShaderProgID = glCreateProgram();
    glAttachShader(ShaderProgID, vShaderID);
    glAttachShader(ShaderProgID, fShaderID);
}

void Shader::LinkShaderProgram() {
    // shader programs
    glLinkProgram(ShaderProgID);

    glGetProgramiv(ShaderProgID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ShaderProgID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::ReleaseShaders() 
{
    glDeleteShader(vShaderID);   // os objetos do shader não são mais necessários, 
    vShaderID = 0;               // DeleteShader ignora IDs com valor zero, evita erro de memoria

    glDeleteShader(fShaderID); // ja foram vinculados e compilados   
    fShaderID = 0;
}

void Shader::Use() {
    glUseProgram(ShaderProgID);
}

std::string Shader::GetVertexShader() {
    return vertexShader.str();
}

unsigned int Shader::GetVertexShaderID() {
    return vShaderID;   
}

std::string Shader::GetFragmentShader() {
    return fragmentShader.str();
}

unsigned int Shader::GetFragmentShaderID() {
    return fShaderID;   
}

std::string Shader::GetShaderProgram() {
    return shaderProgram.str();
}

unsigned int Shader::GetShaderProgramID() {
    return ShaderProgID;   
}

std::string Shader::GetError() {
    return error.str();
}

int Shader::GetSuccessStatus() {
    return success;
}

char* Shader::GetInfoLog() {
    return infoLog; // retorna ponteiro para array
}