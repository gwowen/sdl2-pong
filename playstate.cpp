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
#include "constants.h"

playState playState::m_playState;

void playState::Init( gameEngine* game ) {
    
    myBat.Load( "../bat.png", game->m_Renderer, 100, 100, 10, 101 );
    
}

void playState::Cleanup() {
    myBat.Cleanup();
    
    
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
        
        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 ) {
            switch( event.key.keysym.sym ) {
                case SDLK_w: myBat.batYVel -= BAT_VEL; break;
                case SDLK_s: myBat.batYVel += BAT_VEL; break;
                case SDLK_ESCAPE: game->Quit();
                default:break;
            }
        }
        else if( event.type == SDL_KEYUP  && event.key.repeat == 0 ) {
            switch( event.key.keysym.sym ) {
                case SDLK_w: myBat.batYVel += BAT_VEL; break;
                case SDLK_s: myBat.batYVel -= BAT_VEL; break;
                default:break;
            }
        }
    }
}

void playState::Update( gameEngine* game) {
    myBat.Loop();
}

void playState::Draw( gameEngine* game) {
    SDL_SetRenderDrawColor( game->m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( game->m_Renderer );
    myBat.Render( game->m_Renderer );
    SDL_RenderPresent( game->m_Renderer );
}
