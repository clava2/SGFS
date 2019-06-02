cmake_minimum_required(VERSION 3.0.0)
project(SGFS VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(SGFS 
        src/FrameWork/Game.cpp 
        src/FrameWork/Timer.cpp 
        src/examples/example1.cpp 
        src/Button.cpp 
        src/Label.cpp
        src/commonFunction.cpp
        src/Window.cpp)
target_link_libraries(SGFS SDL2 SDL2_ttf SDL2_image SDL2_gfx yaml-cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
