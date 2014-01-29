/* 
 * File:   bat.h
 * Author: gareth
 *
 * Created on 28 January 2014, 20:57
 */

#ifndef BAT_H
#define	BAT_H

#include "gameobject.h"
#include "constants.h"

class Bat: public gameObject {
    public: 
        int batXVel;
        int batYVel;
        int batRealMiddle;
        
        Bat();
        void Load( std::string file, SDL_Renderer* &batLoadRenderer, int x, int y, int width, int height );
        void Render( SDL_Renderer* & batDrawRenderer );
        void Cleanup();
        void Loop();
};


#endif	/* BAT_H */

