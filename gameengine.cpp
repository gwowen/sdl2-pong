//gameengine.cpp
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameengine.h"
#include "gamestate.h"

bool gameEngine::Init( const char* title, int width, int height ) {
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        printf( "Failed to start SDL\n");
        return false;
    }
    
    m_Window = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, 
                                        SDL_WINDOWPOS_UNDEFINED, 
                                        width, 
                                        height,
                                        SDL_WINDOW_SHOWN );
    if( m_Window == NULL ) {
        printf( "Could not create window. SDL Error %s", SDL_GetError() );
        return 1;
    }
    
    m_Screen = SDL_GetWindowSurface( m_Window );
    
    m_Running = true;
    printf( "gameEngine init\n" );
    
    return true;
    
}

void gameEngine::Cleanup() {
    while(!states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
    
    printf( "gameEngine cleanup\n" );
    SDL_DestroyWindow( m_Window );
    SDL_Quit();
}

void gameEngine::changeState(gameState* state) {
    if( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
    
    states.push_back( state );
    states.back()->Init();
    
}

void gameEngine::pushState(gameState* state) {
    if( !states.empty() ){
        states.back()->Pause();
    }
    
    states.push_back( state );
    states.back()->Init();
}

void gameEngine::popState() {
    if( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
   
    if( ! states.empty() ) {
        states.back()->Resume();
    }
}

void gameEngine::handleEvents() {
    states.back()->handleEvents( this );
}

void gameEngine::Update() {
    states.back()->Update( this );
    
}

void gameEngine::Draw() {
    states.back()->Draw( this );
    
}
