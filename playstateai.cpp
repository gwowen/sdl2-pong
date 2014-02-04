#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "gamestate.h"
#include "gameengine.h"
#include "playstateai.h"
#include "introstate.h"
#include "graphics.h"
#include "constants.h"
#include "ball.h"

playStateAI playStateAI::m_playStateAI;

void playStateAI::Init( gameEngine* game ) {
    playerBat.Load( "../bat.png", game->m_Renderer, 50, 100, 10, 101 );
    aiBat.Load( "../bat.png", game->m_Renderer, 590, 100, 10, 101 );
    myBall.Load( "../ball.png", game->m_Renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, 20 );
    
    gameObject::objectList.push_back( &playerBat );
    gameObject::objectList.push_back( &aiBat );
    gameObject::objectList.push_back( &myBall );
    
    scoreFont = TTF_OpenFont( "../pager.ttf", 28 );
    
}

void playStateAI::Cleanup() {
    for( int i = 0; i < gameObject::objectList.size(); i++ ) {
        if( !gameObject::objectList[ i ] ) continue;
        gameObject::objectList[ i ]->Cleanup();
    }
}


void playStateAI::Pause() {
    
}

void playStateAI::Resume() {
    
}

void playStateAI::handleEvents( gameEngine* game ) {
    SDL_Event event;
    if( SDL_PollEvent( &event ) ) {
        
        if( event.type == SDL_QUIT ) {
            game->Quit();
        }
        
        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 ) {
            switch( event.key.keysym.sym ) {
                case SDLK_w: playerBat.batYVel -= BAT_VEL; break;
                case SDLK_s: playerBat.batYVel += BAT_VEL; break;
                case SDLK_ESCAPE: game->Quit(); break;
                case SDLK_SPACE: game->changeState( introState::Instance() );
                default:break;
            }
        }
        else if( event.type == SDL_KEYUP  && event.key.repeat == 0 ) {
            switch( event.key.keysym.sym ) {
                case SDLK_w: playerBat.batYVel += BAT_VEL; break;
                case SDLK_s: playerBat.batYVel -= BAT_VEL; break;
                default:break;
            }
        }
    }
    
    aiBat.batRealMiddle = aiBat.objectBox.y + ( BAT_HEIGHT / 2 );
    
    if( myBall.ballXVel < 0 ) {
        if( aiBat.batRealMiddle < 298 ) {
            aiBat.batYVel += BAT_VEL;
        }
        
        else if( aiBat.batRealMiddle > 302 ) {
                aiBat.batYVel -= BAT_VEL;
        }
    }
    
    else if( myBall.ballXVel > 0 ) {
        if ( aiBat.batRealMiddle != myBall.objectBox.y ) {
            if ( myBall.objectBox.y < aiBat.batRealMiddle ) {
                aiBat.batYVel -= BAT_VEL;
            }
            else if( myBall.objectBox.y < aiBat.batRealMiddle ) {
                aiBat.batYVel += BAT_VEL;
            }
        }
    }  
} 

void playStateAI::Update( gameEngine* game ) {
    playerBat.Loop();
    aiBat.Loop();
    myBall.Loop( playerBat.objectBox, aiBat.objectBox );
    snprintf( p1ScoreConv, sizeof( p1ScoreConv ), "%d", myBall.p1Score);
    snprintf( p2ScoreConv, sizeof( p2ScoreConv ), "%d", myBall.p2Score);
    p1ScoreText = Texture::drawText( scoreFont, game->m_Renderer, p1ScoreConv );
    p2ScoreText = Texture::drawText( scoreFont, game->m_Renderer, p2ScoreConv );
}

void playStateAI::Draw( gameEngine* game) {
    SDL_SetRenderDrawColor( game->m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( game->m_Renderer );
    
    for( int i = 0; i < gameObject::objectList.size(); i++ ) {
        if( !gameObject::objectList[i ] ) continue;
        gameObject::objectList[ i ]->Render( game->m_Renderer );
    }
    
    Texture::textureDraw( p1ScoreText, game->m_Renderer, 300, 430 );
    Texture::textureDraw( p2ScoreText, game->m_Renderer, 340, 430 );
    SDL_RenderPresent( game->m_Renderer );
}