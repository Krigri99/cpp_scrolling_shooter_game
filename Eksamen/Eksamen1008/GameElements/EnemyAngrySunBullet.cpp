#include "EnemyAngrySunBullet.h"

void EnemyAngrySunBullet::draw() {
    SDLElement::draw();
}

void EnemyAngrySunBullet::update() {
    //Switch between frames to make animation for EnemyAngrySunBullet
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));

    //Set direction and speed for bullet
    mVelocity.setY(7);

    SDLElement::update();
}
