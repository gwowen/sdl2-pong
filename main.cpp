//main.cpp -  displays title screen, most of the magic happens elsewhere!
#include "gameengine.h"
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
