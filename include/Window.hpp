#include <cstdlib>
#include "GLFW/glfw3.h"

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
		void updateClearColor(GLfloat* color);
		const void checkIfValidAddr();
		inline const void checkIfGlfwInit() { if (!glfwInit()) exit(-1); }
		GLFWwindow* getWindowAddr() { return this->window; }

};