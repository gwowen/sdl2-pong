/* 
 * File:   gameengine.h
 * Author: gareth
 *
 * Created on 16 January 2014, 20:16
 */

#ifndef GAMEENGINE_H
#define	GAMEENGINE_H

#include <SDL2/SDL.h>
#include <vector>
#include "constants.h"

using namespace std;

class gameState;

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
    
    //game's window & renderer
    
    SDL_Window* m_Window;
    
    SDL_Renderer* m_Renderer;
    
private:
    //game state stack... which will be staying as just one instance for a while...
    vector<gameState*> states;
    //running variable
    bool m_Running;
};



#endif	/* GAMEENGINE_H */

