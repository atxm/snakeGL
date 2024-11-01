#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <utility>
#include "Shader.hpp"
#include "GLFW/glfw3.h"

std::string read(const std::string& file);

int main()
{
    srand(time(0));

    GLfloat vertices[] =
    {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.0f,  0.5f,  0.0f
    };

    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(500, 500, "snakeGL — by Atom", NULL, NULL);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    
    unsigned int VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    Shader vtxShader;
    Shader fmtShader;

    // vertex shader
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

    // fragment shader
    const char * fragmentShaderSource = "#version 410\nout vec4 FragColor;\nvoid main()\n{\nFragColor = vec4(0.88f, 0.69f, 1.0f, 1.0f);\n}";
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    int  fragmentSuccess;
    char infoLogDos[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);
    if (!fragmentSuccess)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLogDos);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLogDos << std::endl;
    }

    // creating shader program

    unsigned shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShaderID);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int  programSuccess;
    char infoLogTres[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &programSuccess);

    if (!programSuccess)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLogTres);
        std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLogDos << std::endl;
    }

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShader);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_UP) || glfwGetKey(window, GLFW_KEY_W)) glClearColor(1.0 / (rand() % 5 + 1), 1.0 / (rand() % 5 + 1), 1.0 / (rand() % 5 + 1), 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

std::string read(const std::string& file)
{
    std::ifstream stream(file);

    std::string content, line;

    if (!stream) return "Couldn't read file!";

    while (std::getline(stream, line)) content += line + "\n";

    return content;
}
