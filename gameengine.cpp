//gameengine.cpp
#include <stdio.h>
#include "gameengine.h"
#include "gamestate.h"

//gameEngine::Init - used to initially set up the window, initialize SDL, etc.
bool gameEngine::Init( const char* title, int width, int height ) {
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        printf( "Failed to start SDL\n");
        return false;
    }
    
    if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1") ) {
        printf( "Warning: VSync not enabled" );
        return false;
    }
    
    if( TTF_Init() < 0 ) {
        printf( "TTF Init failed\n" );
        return false;
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

//gameEngine::Cleanup - cleans up game states, shuts down SDL
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

//gameEngine::changeState - handles changes between game states and initializes them
void gameEngine::changeState(gameState* state) {
    if( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
    
    states.push_back( state );
    states.back()->Init( this );
    
}

//gameEngine::pushState - pauses existing state and pushes a new one onto the stack
void gameEngine::pushState(gameState* state) {
    if( !states.empty() ){
        states.back()->Pause();
    }
    
    states.push_back( state );
    states.back()->Init( this );
}

//gameEngine::popState - cleans up existing state and removes it
void gameEngine::popState() {
    if( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
   
    if( ! states.empty() ) {
        states.back()->Resume();
    }
}

//gameEngine::handleEvents - calls the events handler of a state
void gameEngine::handleEvents() {
    states.back()->handleEvents( this );
}

//gameEngine::Update - calls the update routine of a state
void gameEngine::Update() {
    states.back()->Update( this );
    
}

//gameEngine::Draw - calls the draw function of a state
void gameEngine::Draw() {
    states.back()->Draw( this );
    
}
