#include "bat.h"

Bat::Bat() {
    batXVel = 0;
    batYVel = 0;
}

void Bat::Load(std::string file, SDL_Renderer*& batLoadRenderer, int x, int y, int width, int height) {
    gameObject::Load( file, batLoadRenderer, x, y, width, height );
    
}

void Bat::Render(SDL_Renderer*& batDrawRenderer) {
    gameObject::Render( batDrawRenderer );
    
}

void Bat::Loop() {
    objectBox.y += batYVel;
    
    if( objectBox.y < 0) {
        objectBox.y = 0;
    }
    else if( objectBox.y + objectBox.h > SCREEN_HEIGHT ) {
        objectBox.y = SCREEN_HEIGHT - objectBox.h;
    }
}

void Bat::Cleanup() {
    gameObject::Cleanup();
}