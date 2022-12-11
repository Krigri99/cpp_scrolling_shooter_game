#include "LifeLost.h"

void LifeLost::draw() {
    SDLElement::draw();
}

void LifeLost::update() {
    //Switch between frames to make animation for LifeLost information box when losing a life
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));

    //Set direction and speed for LifeLost-header over screen
    mVelocity.setX(10);

    SDLElement::update();
}
