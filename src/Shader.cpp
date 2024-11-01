#include "Shader.hpp"

void Shader::initializeShader()
{
    
}

/*           the process of developing a vertex shader:

    std::string vertexShaderSource = read("src/vertexShader.glsl");
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderID);
    int  vertexSuccess;
    char infoLog[512];
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &vertexSuccess);
    if (!vertexSuccess)
    {
        glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
*/

// convert the code to a const char * within the class and call glShaderSource() within the initializeShader() member function for vtxShader
