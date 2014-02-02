/* 
 * File:   introstate.h
 * Author: gareth
 *
 * Created on 02 February 2014, 00:10
 */

#ifndef INTROSTATE_H
#define	INTROSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"

class introState : public gameState {
    public:
        void Init( gameEngine* game );
        void Cleanup();
        void handleEvents( gameEngine* game );
        void Draw( gameEngine* game);
        void Pause();
        void Resume();
        void Update( gameEngine* game );
        
        static introState* Instance() {
            return &m_introState;
        }
        
    protected:
        introState() {};
        
    private:
        static introState m_introState;
        SDL_Texture* introScreen;
};



#endif	/* INTROSTATE_H */

