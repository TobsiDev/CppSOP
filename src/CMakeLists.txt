add_library(src 
            render/window/win.h
            render/window/win.cpp
            )


find_package(SDL2 CONFIG REQUIRED)

target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(src PRIVATE SDL2::SDL2 SDL2::SDL2main)