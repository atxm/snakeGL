#include "Program.hpp"

Program::Program(Shader* v, Shader* f) : programID(glCreateProgram()), vtxShader(v), fmtShader(f)
{
    glAttachShader(this->programID, v->getShaderID());
    glAttachShader(this->programID, f->getShaderID());
    glLinkProgram(this->programID);

    int  programSuccess;
    char infoLogTres[512];

    glGetProgramiv(this->programID, GL_LINK_STATUS, &programSuccess);

    if (!programSuccess)
    {
        glGetProgramInfoLog(this->programID, 512, NULL, infoLogTres);
        std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLogTres << std::endl;
    }
}
