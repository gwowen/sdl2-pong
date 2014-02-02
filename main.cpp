//appwindow.cpp -  a basic SDL window
#include "gameengine.h"
#include "playstate.h"
#include "introstate.h"

int main( int argc, char* argv[] ) {
    gameEngine game;
    
    if( !game.Init("SDL2 Pong") ) {
        printf( "Game failed to initialize\n");
    }
    
    //game.changeState( playState::Instance() );
    game.changeState( introState::Instance() );
    
    while( game.Running() ) {
       game.handleEvents();
       game.Update();
       game.Draw();
    }
    
    game.Cleanup();
    
    return 0;
}
