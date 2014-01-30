/* 
 * File:   ball.h
 * Author: gareth
 *
 * Created on 30 January 2014, 21:57
 */

#ifndef BALL_H
#define	BALL_H
#include "gameobject.h"
#include "constants.h"

class Ball: public gameObject {
    
    public:
        int ballXVel;
        int ballYVel;
        
        Ball();
        void Load( std::string file, SDL_Renderer* &ballLoadRenderer, int x, int y, int width, int height );
        void Loop();
        void Render( SDL_Renderer* & ballDrawRenderer );
        bool Collide();
        void Cleanup();
};


#endif	/* BALL_H */

