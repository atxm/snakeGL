#include "Program.hpp"

Program::Program(Shader* v, Shader* f) : programID(glCreateProgram()), vtxShader(v), fmtShader(f)
{
    glAttachShader(this->programID, v->getShaderID());
    glAttachShader(this->programID, f->getShaderID());
    glLinkProgram(this->programID);
}