#include "SpaceShipBullet.h"

void SpaceShipBullet::draw() {
        SDLElement::draw();
}

void SpaceShipBullet::update() {
    //Switch between frames to make animation for SpaceShipBullet
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));

    //Set direction and speed for bullet
    mVelocity.setY(-25);

    SDLElement::update();
}