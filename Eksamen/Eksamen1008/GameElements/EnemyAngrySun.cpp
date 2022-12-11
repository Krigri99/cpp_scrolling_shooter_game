#include "EnemyAngrySun.h"

EnemyAngrySun::EnemyAngrySun(const LoadParameters *params)  : SDLElement(params){
    //Set initial direction and speed for EnemyAngrySun
    mVelocity.setX(4);
    mVelocity.setY(0.5);
}

void EnemyAngrySun::draw() {
    for (auto & bullets : mAngrySunBulletElement) {
        bullets -> draw();
    }

    SDLElement::draw();
}

void EnemyAngrySun::update() {
    //Switch between frames to make animation for EnemyAngrySun
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));

    mAngrySunBullet = new EnemyAngrySunBullet(new LoadParameters(mPos.getX() + 22, mPos.getY(), 15, 40, "angrySunBullet"));

    //Push new bullet in vector (and play audio) if empty
    //If new bullet goes out of screen, clear vector and pause audio (if necessary)
    if (mAngrySunBulletElement.empty() && mPos.getX() < 510) {
        mAngrySunBulletElement.push_back(mAngrySunBullet);
        tdAudioEnemyAngrySun::Instance() -> playAudio();
    }
    if (mAngrySunBulletElement[0]->getPos().getY() > 700) {
        mAngrySunBulletElement.clear();
        tdAudioEnemyAngrySun::Instance() -> pauseAudio();
    }

    for (auto & bullets : mAngrySunBulletElement) {
        bullets -> update();
    }

    //Limit the range of angrySun
    if (mPos.getX() < 10) {
        mVelocity.setX(4);
    } else if (mPos.getX() > 600) {
        mVelocity.setX(-4);
    }

    if (mPos.getY() < 20) {
        mVelocity.setY(0.5);
    } else if (mPos.getY() > 40) {
        mVelocity.setY(-0.5);
    }

    SDLElement::update();
}

void EnemyAngrySun::clean() {
    mAngrySunBulletElement.clear();
}

EnemyAngrySun::~EnemyAngrySun() {
    delete mAngrySunBullet;
}
