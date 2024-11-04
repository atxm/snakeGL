#include "Shader.hpp"

void Shader::initializeShader()
{
    const char * source = (this->code).c_str();
    this->shaderID = glCreateShader(this->getShaderGLType());
    glShaderSource(this->shaderID, 1, &source, NULL);
    glCompileShader(this->shaderID);
    int success;
    glGetShaderiv(this->shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(this->shaderID, 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::";
        switch (this->type)
        {
            case UNDEFINED: std::cout << "UNDEFINED"; break;
            case VERTEX:    std::cout << "VERTEX";    break;
            case FRAGMENT:  std::cout << "FRAGMENT";  break;
            case GEOMETRY:  std::cout << "GEOMETRY";  break;
        }
        std::cout << "::COMPILATION_FAILED\n" << this->infoLog << std::endl;
    }
    
}

Shader::Shader(const SHADER_TYPE type, const std::string& code) : type(type), code(code)
{
    switch(type)
    {
        case UNDEFINED: this->GLtype = 0;                  break;
        case VERTEX:    this->GLtype = GL_VERTEX_SHADER;   break;
        case FRAGMENT:  this->GLtype = GL_FRAGMENT_SHADER; break;
        case GEOMETRY:  this->GLtype = GL_GEOMETRY_SHADER; break;
    }
}
