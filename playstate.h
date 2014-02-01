/* 
 * File:   playstate.h
 * Author: gareth
 *
 * Created on 16 January 2014, 20:17
 */

#ifndef PLAYSTATE_H
#define	PLAYSTATE_H
#include <SDL2/SDL.h>
#include "gamestate.h"
#include "gameobject.h"
#include "bat.h"
#include "ball.h"

class playState: public gameState {
    
    public:
        void Init( gameEngine* game );
        void Cleanup();
        
        void Pause();
        void Resume();
        
        void handleEvents( gameEngine* game );
        void Update( gameEngine* game );
        void Draw( gameEngine* game );
        
        static playState* Instance() {
          return &m_playState;  
        }
        
        protected:
            playState() {}
            
        private:
            static playState m_playState;
            
            Bat myBat1;
            
            Bat myBat2;
            
            Ball myBall;
            
            char p1ScoreConv[ 10 ];
            char p2ScoreConv[ 10 ];
            
            SDL_Texture* p1ScoreText;
            SDL_Texture* p2ScoreText;
            
            TTF_Font *scoreFont;
            
    
};



#endif	/* PLAYSTATE_H */

