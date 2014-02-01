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
#include "ball.h"

playState playState::m_playState;

void playState::Init( gameEngine* game ) {
    
    myBat1.Load( "../bat.png", game->m_Renderer, 50, 100, 10, 101 );
    myBat2.Load( "../bat.png", game->m_Renderer, 590, 100, 10, 101 );
    myBall.Load( "../ball.png", game->m_Renderer, 400, 300, 20, 20 );
    
    gameObject::objectList.push_back( &myBat1 );
    gameObject::objectList.push_back( &myBat2 );
    gameObject::objectList.push_back( &myBall );
    
    scoreFont = TTF_OpenFont( "../pager.ttf", 28 );
    textTest = Texture::drawText( scoreFont, game->m_Renderer, "Hello World");
    
}

void playState::Cleanup() {
    //myBat1.Cleanup();
    //myBall.Cleanup();
    for( int i = 0; i < gameObject::objectList.size(); i++ ) {
        if( !gameObject::objectList[ i ] ) continue;
        gameObject::objectList[ i ]->Cleanup();
    }
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
                case SDLK_w: myBat1.batYVel -= BAT_VEL; break;
                case SDLK_s: myBat1.batYVel += BAT_VEL; break;
                case SDLK_UP: myBat2.batYVel -= BAT_VEL; break;
                case SDLK_DOWN: myBat2.batYVel += BAT_VEL; break;
                case SDLK_ESCAPE: game->Quit();
                default:break;
            }
        }
        else if( event.type == SDL_KEYUP  && event.key.repeat == 0 ) {
            switch( event.key.keysym.sym ) {
                case SDLK_w: myBat1.batYVel += BAT_VEL; break;
                case SDLK_s: myBat1.batYVel -= BAT_VEL; break;
                 case SDLK_UP: myBat2.batYVel += BAT_VEL; break;
                case SDLK_DOWN: myBat2.batYVel -= BAT_VEL; break;
                default:break;
            }
        }
    }
}

void playState::Update( gameEngine* game) {
    myBat1.Loop();
    myBat2.Loop();
    myBall.Loop( myBat1.objectBox, myBat2.objectBox );
}

void playState::Draw( gameEngine* game) {
    SDL_SetRenderDrawColor( game->m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( game->m_Renderer );
    for( int i = 0; i < gameObject::objectList.size(); i++ ) {
        if( !gameObject::objectList[i ] ) continue;
        gameObject::objectList[ i ]->Render( game->m_Renderer );
    }
    //myBat1.Render( game->m_Renderer );
    //myBall.Render( game->m_Renderer );
    Texture::textureDraw( textTest, game->m_Renderer, 30, 30 );
    SDL_RenderPresent( game->m_Renderer );
}
