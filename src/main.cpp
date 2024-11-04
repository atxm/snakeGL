#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <utility>
#include "Shader.hpp"
#include "Program.hpp"
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

    // vertex shader
    Shader* vtxShader = new Shader(VERTEX, read("src/vertexShader.glsl"));
    vtxShader->initializeShader();

    // fragment shader
    Shader* fmtShader = new Shader(FRAGMENT, read("src/fragmentShader.glsl"));
    fmtShader->initializeShader();

    // creating shader program
    Program* triangleProgram = new Program(vtxShader, fmtShader);

    int  programSuccess;
    char infoLogTres[512];

    glGetProgramiv(triangleProgram->getProgramID(), GL_LINK_STATUS, &programSuccess);

    if (!programSuccess)
    {
        glGetProgramInfoLog(triangleProgram->getProgramID(), 512, NULL, infoLogTres);
        std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLogTres << std::endl;
    }

    delete vtxShader;
    delete fmtShader;

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    int counter;

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_UP) || glfwGetKey(window, GLFW_KEY_W)) glClearColor(1.0 / (rand() % 5 + 1), 1.0 / (rand() % 5 + 1), 1.0 / (rand() % 5 + 1), 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(triangleProgram->getProgramID());
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete triangleProgram;
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
