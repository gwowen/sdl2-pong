/* 
 * File:   playstateai.h
 * Author: gareth
 *
 * Created on 03 February 2014, 23:41
 */

#ifndef PLAYSTATEAI_H
#define	PLAYSTATEAI_H
#include <SDL2/SDL.h>
#include "gamestate.h"
#include "gameobject.h"
#include "bat.h"
#include "ball.h"

class playStateAI: public gameState {
    
    public:
        void Init( gameEngine* game );
        void Cleanup();
        
        void Pause();
        void Resume();
        
        void handleEvents( gameEngine* game );
        void Update( gameEngine* game );
        void Draw( gameEngine* game );
        
        static playStateAI* Instance() {
          return &m_playStateAI;  
        }
        
        protected:
            playStateAI() {}
            
        private:
            static playState m_playStateAI;
            
            Bat myBat1;
            
            Bat myBat2;
            
            Ball myBall;
            
            char p1ScoreConv[ 10 ];
            char p2ScoreConv[ 10 ];
            
            SDL_Texture* p1ScoreText;
            SDL_Texture* p2ScoreText;
            
            TTF_Font *scoreFont;
            
    
};



#endif	/* PLAYSTATEAI_H */

