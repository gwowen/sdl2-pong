#include "ball.h"

Ball::Ball() {
    ballXVel = BALL_VEL;
    ballYVel = BALL_VEL;
}

void Ball::Load(std::string file, SDL_Renderer*& ballLoadRenderer, int x, int y, int width, int height) {
    gameObject::Load( file, ballLoadRenderer, x, y, width, height );
    
}

void Ball::Render(SDL_Renderer*& ballDrawRenderer) {
    gameObject::Render( ballDrawRenderer );
    
}

void Ball::Loop() {
    objectBox.x += ballXVel;
    
    if( objectBox.x < 0 ) {
        objectBox.x = 0;
        ballXVel = -ballXVel;
    }
    else if( objectBox.x + objectBox.w > SCREEN_WIDTH ) {
        //objectBox.x = SCREEN_WIDTH - objectBox.w;
        ballXVel = -ballXVel;
    }
    
    objectBox.y += ballYVel;
    if( objectBox.y <= 0 ) {
        objectBox.y = 0;
        ballYVel = -ballYVel;
    }
    else if( objectBox.y + objectBox.h > SCREEN_HEIGHT ) {
        objectBox.y = SCREEN_HEIGHT - objectBox.h;
        ballYVel = -ballYVel;
    }
}



void Ball::Cleanup() {
    gameObject::Cleanup();
}
