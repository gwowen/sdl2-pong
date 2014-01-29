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

void Bat::Cleanup() {
    gameObject::Cleanup();
}