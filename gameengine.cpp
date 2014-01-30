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
    
    if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1") ) {
        printf( "Warning: VSync not enabled" );
    }
    
    m_Window = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, 
                                        SDL_WINDOWPOS_UNDEFINED, 
                                        width, 
                                        height,
                                        SDL_WINDOW_SHOWN );
    
    if( m_Window == NULL ) {
        printf( "Could not create window. SDL Error %s", SDL_GetError() );
        return false;
    }
    
    m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED );
    
    if( m_Renderer == NULL) {
        printf( "Could not create renderer. SDL Error %s\n", SDL_GetError() );
        return false;
    }
    else {
        //set renderer draw color
        SDL_SetRenderDrawColor( m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        
        //initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
            printf( "SDL image could not initialize. SDL_image error:%s\n", IMG_GetError() );
            return false;
        }
    }
    
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
    SDL_DestroyRenderer( m_Renderer );
    IMG_Quit();
    SDL_Quit();
}

void gameEngine::changeState(gameState* state) {
    if( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
    
    states.push_back( state );
    states.back()->Init( this );
    
}

void gameEngine::pushState(gameState* state) {
    if( !states.empty() ){
        states.back()->Pause();
    }
    
    states.push_back( state );
    states.back()->Init( this );
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
