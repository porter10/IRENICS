#include "editor.h"

void windowframe();
void windowstyling();
void dockspace();
void windows(unsigned int texture);
void renderwindowframe();

Editor::Editor(GLFWwindow* window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version.c_str());
    ImGuizmo::Enable(true);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_DockingEnable;
}



void Editor::UI(unsigned int texture)
{
    windowframe();

    windowstyling();
    dockspace();
    windows(texture);

    renderwindowframe(); 
}


Editor::~Editor()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void windowframe()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void windowstyling()
{
    ImGuiStyle* style = &ImGui::GetStyle();
    
    style->WindowRounding = 0.0f;
    style->WindowPadding = ImVec2(0.0f, 0.0f);
    style->WindowBorderSize = 0.0f;
    style->TabRounding = 0.0f;
    style->WindowMenuButtonPosition = ImGuiDir_None;
}

void dockspace()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGuiID dockspaceid = ImGui::GetID("DOCKSPACE ID");
    ImGuiWindowFlags windowflag = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
    

    if (!ImGuiConfigFlags_DockingEnable)
        io.ConfigFlags = ImGuiConfigFlags_DockingEnable;

    ImGui::SetNextWindowPos(viewport->GetWorkPos());
    ImGui::SetNextWindowSize(viewport->GetWorkSize());
    ImGui::SetNextWindowViewport(viewport->ID);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.05f, 0.05f));

    ImGui::Begin("DockSpace", nullptr, windowflag);
    ImGui::DockSpace(dockspaceid);
    ImGui::End();

    ImGui::PopStyleVar();
}

void windows(unsigned int texture)
{
    ImGuiWindowFlags windowflag = ImGuiWindowFlags_NoCollapse;

    ImGui::Begin("Hierarchy", nullptr, windowflag);
    ImGui::End();   

    ImGui::Begin("Viewpoint", nullptr, windowflag);
    ImGui::Image((void*)texture, ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 18));
    ImGui::End(); 

    ImGui::Begin("Inspector", nullptr, windowflag);
    ImGui::End(); 

    ImGui::Begin("Console", nullptr, windowflag);
    ImGui::End(); 
}

void renderwindowframe()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}