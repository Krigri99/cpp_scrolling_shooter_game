#include <SDL_timer.h>
#include "EnemyAlien.h"
#include "EnemyAlienBullet.h"

EnemyAlien::EnemyAlien(const LoadParameters *params) : SDLElement(params){
    //Set initial direction and speed for EnemyAlien
    mVelocity.setX(3.5);
    mVelocity.setY(2);
}

void EnemyAlien::draw() {
    for (auto & bullets : mAlienBulletElement) {
        bullets -> draw();
    }

    SDLElement::draw();
}

void EnemyAlien::update() {
    //Switch between frames to make animation for EnemyAlien
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 3));

    mAlienBullet = new EnemyAlienBullet(new LoadParameters(mPos.getX() + 22, mPos.getY(), 14, 20, "alienBullet"));

    //Push new bullet in vector (and play audio) if empty
    //If new bullet goes out of screen, clear vector and pause audio (if necessary)
    if (mAlienBulletElement.empty() && mPos.getX() < 510) {
        mAlienBulletElement.push_back(mAlienBullet);
        tdAudioEnemyAlien::Instance() -> playAudio();
    }
    if (mAlienBulletElement[0]->getPos().getY() > 700) {
        mAlienBulletElement.clear();
        tdAudioEnemyAlien::Instance() -> pauseAudio();
    }

    for (auto & bullets : mAlienBulletElement) {
        bullets -> update();
    }

    //Limit the range of alien
    if (mPos.getX() < 10) {
        mVelocity.setX(3.5);
    } else if (mPos.getX() > 580) {
        mVelocity.setX(-3.5);
    }

    if (mPos.getY() < 50) {
        mVelocity.setY(2);
    } else if (mPos.getY() > 200) {
        mVelocity.setY(-2);
    }

    SDLElement::update();
}

void EnemyAlien::clean() {
    mAlienBulletElement.clear();
}

EnemyAlien::~EnemyAlien() {
    delete mAlienBullet;
}