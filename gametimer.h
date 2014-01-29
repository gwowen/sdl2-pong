/* 
 * File:   gametimer.h
 * Author: gareth
 *
 * Created on 29 January 2014, 23:14
 */

#ifndef GAMETIMER_H
#define	GAMETIMER_H

#include <SDL2/SDL.h>

class gameTimer {
private:
    int startTime;
    int pauseTime;
    bool paused;
    bool started;
    
public:
    gameTimer();
    void startGameTimer();
    void stopGameTimer();
    void pauseGameTimer();
    void unpauseGameTimer();
    
    int getTime();
    
    bool checkStarted();
    bool checkPaused();
};



#endif	/* GAMETIMER_H */

