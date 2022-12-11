#include "EnemyAlienBullet.h"

void EnemyAlienBullet::draw() {
    SDLElement::draw();
}

void EnemyAlienBullet::update() {
    //Switch between frames to make animation for EnemyAlienBullet
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));

    //Set direction and speed for bullet
    mVelocity.setY(5);

    SDLElement::update();
}
