/* 
 * File:   gamestate.h
 * Author: gareth
 *
 * Created on 16 January 2014, 20:54
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include "gameengine.h"

class gameState {
public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;
    
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    
    virtual void handleEvents( gameEngine* game ) = 0;
    virtual void Update( gameEngine* game ) = 0;
    virtual void Draw( gameEngine* game ) = 0;
    
    void changeState( gameEngine* game, gameState* state ) {
        game->changeState( state );
    }
protected:
    gameState() { }
};



#endif	/* GAMESTATE_H */

