cmake_minimum_required( VERSION 2.8 )

project( pong-SDL2 )

add_definitions( -g `sdl2-config --cflags` )
add_executable( pong-SDL2 main.cpp gameengine.cpp graphics.cpp playstate.cpp gameobject.cpp )
target_link_libraries( pong-SDL2 -lSDL2 -lSDL2_image )