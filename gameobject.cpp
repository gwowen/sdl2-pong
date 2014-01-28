#include "gameobject.h"

std::vector<gameObject*> gameObject::objectList;

gameObject::gameObject() {
    texObject = NULL;
    
}

gameObject::~gameObject() {
    
}

void gameObject::Load( std::string file, SDL_Renderer* &loadRenderer ) {
    texObject = Texture::textureLoad( file.c_str(), loadRenderer );
    printf("Game object loaded %s successfully!\n", file.c_str() );
}

void gameObject::Event() {
    
}

void gameObject::Render( SDL_Renderer* &objRenderer ) {
    Texture::textureDraw( texObject, objRenderer, 100, 100 );
}

void gameObject::Cleanup() {
    SDL_DestroyTexture( texObject );
    texObject = NULL;
}
