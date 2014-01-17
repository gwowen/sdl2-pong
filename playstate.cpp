//playstate.cpp
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"

playState playState::m_playState;

void playState::Init() {
    
    temp = SDL_LoadBMP( "../helloworld.bmp");
    
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
    SDL_BlitSurface( temp, NULL, game->m_Screen, NULL );
    SDL_UpdateWindowSurface( game->m_Window );
    
}
