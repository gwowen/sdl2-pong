#include <SDL2/SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "playstate.h"
#include "introstate.h"

introState introState::m_introState;

void introState::Init( gameEngine* game ) {
    introScreen = Texture::textureLoad( "../titlescreen.png", game->m_Renderer );
}

void introState::Cleanup() {
    SDL_DestroyTexture( introScreen );
    
}

void introState::Update(gameEngine* game) {
    
}

void introState::handleEvents(gameEngine* game) {
    SDL_Event event;
    
    if( SDL_PollEvent( &event ) ) {
        switch( event.type ) {
            case SDL_QUIT:
                game->Quit();
                break;
                
                case SDL_KEYDOWN:
                    switch( event.key.keysym.sym ) {
                        case SDLK_1:
                            game->changeState( playState::Instance() );
                            break;
                            
                        case SDLK_ESCAPE:
                            game->Quit();
                            break;
                            
                        default:break;
                    }
                    break;
        }
    }
    
}

void introState::Draw(gameEngine* game) {
    Texture::textureDraw( introScreen, game->m_Renderer, 0, 0);
    SDL_RenderPresent( game->m_Renderer );
}

void introState::Pause() {
    
}

void introState::Resume() {
    
}