#include <iostream>
#include <string>
#include "glad/glad.h"

#ifndef SHADER_HPP
#define SHADER_HPP

// The Shader object is to be instantiated prior to its use

enum SHADER_TYPE { UNDEFINED, VERTEX, FRAGMENT, GEOMETRY };

class Shader
{
    private:
        SHADER_TYPE type;
        GLenum GLtype;
        int shaderID;
        std::string code;
        char infoLog[512];
    public:
        Shader();
        ~Shader() { glDeleteShader(this->getShaderID()); }
        Shader(const SHADER_TYPE type, const std::string& code);
        int getShaderID() { return this->shaderID; }
        void setShaderType(SHADER_TYPE newType) { this->type = newType; }
        SHADER_TYPE getShaderType() { return this->type; }
        GLenum getShaderGLType() { return this->GLtype; }
        void initializeShader();
};

#endif