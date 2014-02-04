/* 
 * File:   gameobject.h
 * Author: gareth
 *
 * Created on 23 January 2014, 22:50
 */

#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <stdio.h>
#include "graphics.h"

//gameObject class - the base from which all other objects such as bats, balls and so on are derived

class gameObject {
    
protected:
    SDL_Texture* texObject;
    
public:
    static std::vector<gameObject*> objectList;
    
    SDL_Rect objectBox;
    int objXVel;
    int objYVel;
    
    gameObject();
    virtual ~gameObject();
    
    virtual void Load( std::string file, SDL_Renderer* &loadRenderer, int x, int y, int width, int height );
    virtual void Event();
    virtual void Render( SDL_Renderer* &objRenderer );
    virtual void Cleanup();
    
};


#endif	/* GAMEOBJECT_H */

