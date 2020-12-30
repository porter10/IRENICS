#pragma once 

#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/ImGuizmo.h>
#include <iostream>

class Editor
{
private:
    std::string glsl_version = "#version 450 core";

    
public:
    Editor(GLFWwindow* window);

    void UI(unsigned int texture);

    ~Editor();
};

