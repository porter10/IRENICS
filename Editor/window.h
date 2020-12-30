#pragma once 

#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
    GLFWwindow* window;
    unsigned int WIN_WIDTH = 1980;
    unsigned int WIN_HEIGHT = 1080;
    std::string WIN_TITLE = "Lone Engine -- OpenGL 4.5\0";

public:
    Window(); 

    inline int windowopen(){ return !glfwWindowShouldClose(window);}
    inline void windowevent() { return glfwPollEvents();}
    inline void swapbuffer() { return glfwSwapBuffers(window);}
    inline GLFWwindow* getwindow() { return window; }

    ~Window();
};