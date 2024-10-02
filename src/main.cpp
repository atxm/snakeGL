#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <utility>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main()
{
    srand(time(0));

    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(500,500,"TestForMacOS",NULL,NULL);

    glfwMakeContextCurrent(window);
    gladLoadGL();

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_UP) || glfwGetKey(window, GLFW_KEY_W)) glClearColor(1 / (rand() % 10 + 1) ,1 / (rand() % 10 + 1),1 / (rand() % 10 + 1),1);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
