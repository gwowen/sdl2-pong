cmake_minimum_required( VERSION 2.8 )

project( pong-SDL2 )

set( CMAKE_CXX_FLAGS_DEBUG )
set( CMAKE_C_FLAGS_DEBUG )
add_executable( pong-SDL2 main.cpp gameengine.cpp graphics.cpp playstate.cpp playstateai.cpp gameobject.cpp bat.cpp ball.cpp introstate.cpp)
target_link_libraries( pong-SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf )