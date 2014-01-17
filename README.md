sdl2-pong
=========

So there's the old crappy version in SDL 1.2, and the new version in SDL 2.0 which has better rendering capabilities.
As of now I've just used SDL as windowing for opengl stuff, however as I've got a hankering for making some 2D
instead of 3D stuff I'm coming back to SDL 2.0 and its much more advanced capabilities.

It requires SDL, SDL_image and SDL_ttf (all 2.0 versions). At the moment it only builds on Linux, using cmake. To do an
out-of-source build, create a build folder, cd into it and type cmake .., then make.
