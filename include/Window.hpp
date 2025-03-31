#include <cstdlib>
#include <string>
#include "GLFW/glfw3.h"

#ifndef WINDOW_HPP
#define WINDOW_HPP

enum Screen { FULLSCREEN, WINDOWED };

class Window {
	private:
		GLFWwindow* window;
	public:
		Window();
		Window(const char* name);
		Window(const char* name, Screen screen);
		Window(const char* name, int height, int width);
		Window(const char* name, int height, int width, Screen screen);
		const void checkIfValidAddr();
		inline const void checkIfGlfwInit() { if (!glfwInit()) exit(-1); }
		GLFWwindow* getWindowAddr() { return this->window; }

};

#endif
