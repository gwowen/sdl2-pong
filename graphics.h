/* 
 * File:   graphics.h
 * Author: gareth
 *
 * Created on 18 January 2014, 18:09
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Texture {
public:
    Texture();
    
    static SDL_Texture* textureLoad( std::string fileName , SDL_Renderer* &texLoadRenderer);
    
    static void textureDraw( SDL_Texture* & texDrawTex, SDL_Renderer* &texDrawRenderer, int x, int y, 
        SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE  );
};



#endif	/* GRAPHICS_H */

