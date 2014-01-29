#include "gametimer.h"

gameTimer::gameTimer() {
    startTime = 0;
    pauseTime = 0;
    paused = false;
    started = false;
    
}

void gameTimer::startGameTimer() {
    started = true;
    paused = false;
    startTime = SDL_GetTicks();
    
}

void gameTimer::stopGameTimer() {
    started = false;
    paused = false;
    
}

int gameTimer::getTime() {
    if( started == true  ) {
        if( paused == true ) {
            return pauseTime;
        }
        else {
            return SDL_GetTicks() - startTime;
        }
    }
    return 0;
}

void gameTimer::pauseGameTimer() {
    if(  started == true && paused == false ) {
        paused = true;
        pauseTime = SDL_GetTicks() - startTime;
    }
    
}

void gameTimer::unpauseGameTimer() {
    
    if( paused == true ) {
        paused = false;
        startTime = SDL_GetTicks() - pauseTime;
    }
    
}

bool gameTimer::checkStarted() {
    return started;
    
}

bool gameTimer::checkPaused() {
    return paused;
}