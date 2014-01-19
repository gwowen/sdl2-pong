//graphics.cpp
#include "graphics.h"

SDL_Texture* Texture::textureLoad(std::string fileName, SDL_Renderer* &texLoadRenderer) {
    
    SDL_Texture * newTexture = NULL;
    
    SDL_Surface* tempSurface = IMG_Load( fileName.c_str() );
    
    if( tempSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image error:%s\n", fileName.c_str(), IMG_GetError() );
    } else {
        SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0, 0xFF, 0xFF) );
        newTexture = SDL_CreateTextureFromSurface( texLoadRenderer, tempSurface );
        
        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s", fileName.c_str(), SDL_GetError() );
        }
        printf( "%s loaded successfully!\n", fileName.c_str() );
        SDL_FreeSurface( tempSurface );
        }
    return newTexture;
    }

void Texture::textureDraw(SDL_Texture* &texDrawTex, SDL_Renderer*& texDrawRenderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    
    SDL_Rect renderQuad;
    renderQuad.x = x;
    renderQuad.y = y;
    
    SDL_QueryTexture( texDrawTex, NULL, NULL, &renderQuad.w, &renderQuad.h );
    

    
    SDL_RenderCopyEx( texDrawRenderer, texDrawTex, clip, &renderQuad, angle, center, flip);
}

