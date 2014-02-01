#include "ball.h"

Ball::Ball() {
    ballXVel = BALL_VEL;
    ballYVel = BALL_VEL;
    p1Score = 0;
    p2Score = 0;
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
        objectBox.x = SCREEN_WIDTH / 2;
        objectBox.y = SCREEN_HEIGHT / 2;
        p2Score += 1;
        ballXVel = BALL_VEL;
    }
    else if( objectBox.x + objectBox.w > SCREEN_WIDTH ) {
        objectBox.x = SCREEN_WIDTH / 2;
        objectBox.y = SCREEN_HEIGHT / 2;
        p1Score += 1;
        ballXVel = BALL_VEL;
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
        ballXVel = -ballXVel;
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
