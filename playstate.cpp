//playstate.cpp
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"
#include "graphics.h"

playState playState::m_playState;

void playState::Init( gameEngine* game ) {
    
    testTexture = Texture::textureLoad("../bat.png", game->m_Renderer );
    
}

void playState::Cleanup() {
    
}

void playState::Pause() {
    
}

void playState::Resume() {
    
}

void playState::handleEvents( gameEngine* game ) {
    SDL_Event event;
    if( SDL_PollEvent( &event ) ) {
        
        if( event.type == SDL_QUIT ) {
            game->Quit();
        }
        
        if( event.type == SDL_KEYDOWN ) {
            switch( event.key.keysym.sym ) {
                case SDLK_ESCAPE: game->Quit();
                default:break;
            }
        }
    }
}

void playState::Update( gameEngine* game) {
    
}

void playState::Draw( gameEngine* game) {
    SDL_SetRenderDrawColor( game->m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( game->m_Renderer );
    Texture::textureDraw( testTexture, game->m_Renderer, 100, 100 );
    SDL_RenderPresent( game->m_Renderer );
    
}
