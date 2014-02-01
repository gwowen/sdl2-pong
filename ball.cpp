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

void Ball::Loop( SDL_Rect batBox1, SDL_Rect batBox2 ) {
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
    else if ( Collide( batBox1 ) || Collide( batBox2 ) ) {
        ballXVel = -ballXVel * 2;
    }
}

bool Ball::Collide(SDL_Rect collisionTarget) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    leftA = objectBox.x;
    rightA = objectBox.x + objectBox.w;
    topA = objectBox.y;
    bottomA = objectBox.y + objectBox.h;
    
    leftB = collisionTarget.x;
    rightB = collisionTarget.x + collisionTarget.w;
    topB = collisionTarget.y;
    bottomB = collisionTarget.y + collisionTarget.h;
    
    if( bottomA <= topB  || topA >= bottomB || rightA <= leftB || leftA >= rightB ) {
        return false;
    }
    
    return true;
}

void Ball::Cleanup() {
    gameObject::Cleanup();
}
