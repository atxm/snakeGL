#include "Window.hpp"
#include <string>

Window::Window()
{
	checkIfGlfwInit();
	window = glfwCreateWindow(1280, 720, "untitled", NULL, NULL);
	checkIfValidAddr();
}

Window::Window(const char* name)
{
	checkIfGlfwInit();
	window = glfwCreateWindow(1280, 720, name, NULL, NULL);
	checkIfValidAddr();
}

Window::Window(const char* name, Screen screen)
{
	checkIfGlfwInit();
	window = glfwCreateWindow(1280, 720, name, (screen == FULLSCREEN) ? glfwGetPrimaryMonitor() : NULL, NULL);
	checkIfValidAddr();
}

Window::Window(const char* name, int height, int width)
{
	checkIfGlfwInit();
	window = glfwCreateWindow(height, width, name, NULL, NULL);
	checkIfValidAddr();
}

Window::Window(const char* name, int height, int width, Screen screen)
{
	checkIfGlfwInit();
	window = glfwCreateWindow(height, width, name, (screen == FULLSCREEN) ? glfwGetPrimaryMonitor() : NULL, NULL);
	checkIfValidAddr();
}

const void Window::checkIfValidAddr()
{
	if (!window)
	{
		glfwTerminate();
		exit(-1);
	}
}