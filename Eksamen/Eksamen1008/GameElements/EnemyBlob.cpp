#include "EnemyBlob.h"

EnemyBlob::EnemyBlob(const LoadParameters *params) : SDLElement(params){
    //Set initial direction and speed for EnemyBlob
    mVelocity.setX(3);
    mVelocity.setY(2);
}

void EnemyBlob::draw() {
    SDLElement::draw();
}

void EnemyBlob::update() {
    //Switch between frames to make animation for EnemyBlob
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));

    //Limit the range of blob
    if (mPos.getX() < 0) {
        mVelocity.setX(3);

    } else if (mPos.getX() > 590) {
        mVelocity.setX(-3);
    }

    if (mPos.getY() < 200) {
        mVelocity.setY(2);

    } else if (mPos.getY() > 660) {
        mVelocity.setY(-2);
    }

    SDLElement::update();
}