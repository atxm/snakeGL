#include <fstream>
#include "Program.hpp"
#include "Shader.hpp"
#include "Window.hpp"

#define slithering !glfwWindowShouldClose(window->getWindowAddr())

std::string read(const std::string& file);

int main()
{
    srand(time(0));
    
    GLfloat vertices[] =
    {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f,  0.5f, 0.0f,  // top left 
    };

    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    Window* window = new Window("snakeGL — atom", 500, 500, FULLSCREEN);

    glfwMakeContextCurrent(window->getWindowAddr());
    gladLoadGL();

    // vertex shader
    Shader* vtxShader = new Shader(VERTEX, read("../src/vertexShader.glsl"));
    vtxShader->initializeShader();

    // fragment shader
    Shader* fmtShader = new Shader(FRAGMENT, read("../src/fragmentShader.glsl"));
    fmtShader->initializeShader();

    // creating shader program
    Program* triangleProgram = new Program(vtxShader, fmtShader);

    delete vtxShader;
    delete fmtShader;

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (slithering)
    {
        if (glfwGetKey(window->getWindowAddr(), GLFW_KEY_UP) || glfwGetKey(window->getWindowAddr(), GLFW_KEY_W)) glClearColor(1.0 / (rand() % 5 + 1), 1.0 / (rand() % 5 + 1), 1.0 / (rand() % 5 + 1), 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        triangleProgram->useProgram();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window->getWindowAddr());
        glfwPollEvents();
    }

    delete triangleProgram;
    glfwDestroyWindow(window->getWindowAddr());
    delete window;
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
