#include <string>
#include "glad.h"

// The Shader object is to be instantiated prior to its use

enum SHADER_TYPE { UNDEFINED, VERTEX, FRAGMENT, GEOMETRY, COMPUTE };

class Shader
{
    private:
        SHADER_TYPE type;
        std::string code;
        std::string infoLog;
    public:
        Shader();
        Shader(const SHADER_TYPE type, const std::string& code) : type(type), code(code) {};
        ~Shader();
        SHADER_TYPE getShaderType() { return this->type; }
        void setShaderType(SHADER_TYPE newType) { this->type = newType; }
        std::string get;
        void initializeShader();
};