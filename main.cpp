#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "GLFW/glfw3.h"

int main()
{
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(500,500,"TestForMacOS",NULL,NULL);

    glfwMakeContextCurrent(window);
    //gladLoadGL();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
