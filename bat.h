/* 
 * File:   bat.h
 * Author: gareth
 *
 * Created on 28 January 2014, 20:57
 */

#ifndef BAT_H
#define	BAT_H

#include "gameobject.h"

class Bat: public gameObject {
    public: 
        int batXVel;
        int batYVel;
        int batRealMiddle;
        
        Bat();
        void Load( std::string file, SDL_Renderer* &batLoadRenderer );
        void Render( SDL_Renderer* & batDrawRenderer );
        void Cleanup();
};


#endif	/* BAT_H */

