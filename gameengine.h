/* 
 * File:   gameengine.h
 * Author: gareth
 *
 * Created on 16 January 2014, 20:16
 */
#ifndef GAMEENGINE_H
#define	GAMEENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "constants.h"

using namespace std;

class gameState;

//gameEngine class: handles all things such as creation of window, cleanup of game, changing game states, etc.

class gameEngine {
public:
    bool Init( const char* title, int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT );
    void Cleanup();
    void changeState( gameState* state );
    void pushState( gameState* state );
    void popState();
    
    void handleEvents();
    void Update();
    void Draw();
    
    bool Running() { return m_Running; }
    void Quit() { m_Running = false; }
    
    SDL_Window* m_Window;
    
    SDL_Renderer* m_Renderer;
    
private:
    vector<gameState*> states;
    bool m_Running;
};



#endif	/* GAMEENGINE_H */

