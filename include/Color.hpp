#include <glad.h>

class Color
{
    private:
        GLfloat r, g, b;

    public:
        Color() : r(0), g(0), b(0) {}
        Color(GLfloat red, GLfloat green, GLfloat blue) : r(!red || red > GLfloat(1.0) ? red : GLfloat(1.0)), g(!green || green > GLfloat(1.0) ? green : GLfloat(1.0)), b(!blue || blue > GLfloat(1.0) ? blue : GLfloat(1.0)) {}

        GLfloat getRed() const { return r; }
        GLfloat getGreen() const { return g; }
        GLfloat getBlue() const { return b; }

        void setRed(GLfloat red) { r = red; }
        void setGreen(GLfloat green) { g = green; }
        void setBlue(GLfloat blue) { b = blue; }
};