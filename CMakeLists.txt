cmake_minimum_required(VERSION 3.18)
project(Lone)

include_directories(Libraries/include)
include_directories(./)

link_directories(Libraries/lib)

file(GLOB src "Editor/*.cpp" "Graphic/*.cpp")

add_executable(Lone Main/Editormain.cpp ${src})
target_link_libraries(Lone -lguizmo -lglad -ldl -lglfw3 -limgui -lm -lGL -lGLU -lX11 -lpthread)

set_target_properties(Lone 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ../bin/
)