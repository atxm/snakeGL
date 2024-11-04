#include "Shader.hpp"

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

class Program
{
    private:
        unsigned programID;
        Shader* vtxShader;
        Shader* fmtShader;
        Shader* gmtShader;
    public:
        Program() : programID(glCreateProgram()), vtxShader(nullptr), fmtShader(nullptr), gmtShader(nullptr) {}
        Program(Shader* v, Shader* f);
        inline unsigned getProgramID() { return programID; }
        inline void useProgram() { glUseProgram(this->programID); }
        inline void attachShader(Shader* shader) { glAttachShader(this->programID, shader->getShaderID()); }
};

#endif