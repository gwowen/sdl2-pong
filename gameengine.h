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

using namespace std;

class gameState;

class gameEngine {
public:
    bool Init( const char* title, int width = 640, int height = 480 );
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
    
    SDL_Surface* m_Screen;
    
    SDL_Renderer* m_Renderer;
    
private:
    //game state stack... which will be staying as one for a while
    vector<gameState*> states;
    //running variable
    bool m_Running;
};



#endif	/* GAMEENGINE_H */

