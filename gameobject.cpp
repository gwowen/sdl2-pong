#include "gameobject.h"

std::vector<gameObject*> gameObject::objectList;

gameObject::gameObject() {
    texObject = NULL;
    
}

gameObject::~gameObject() {
    
}

void gameObject::Load( std::string file, SDL_Renderer* &loadRenderer, int x, int y, int width, int height ) {
    texObject = Texture::textureLoad( file.c_str(), loadRenderer );
    objectBox.x = x;
    objectBox.y = y;
    objectBox.h = height;
    objectBox.w = width;
    printf("Game object loaded %s successfully!\n", file.c_str() );
}

void gameObject::Event() {
    
}

void gameObject::Render( SDL_Renderer* &objRenderer ) {
    Texture::textureDraw( texObject, objRenderer, objectBox.x, objectBox.y );
}

void gameObject::Cleanup() {
    SDL_DestroyTexture( texObject );
    texObject = NULL;
}
