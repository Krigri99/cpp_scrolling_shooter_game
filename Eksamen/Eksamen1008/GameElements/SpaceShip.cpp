#include "SpaceShip.h"
#include "../Handlers/InputHandler.h"
#include "SpaceShipBullet.h"

void SpaceShip::draw() {
    for (auto & bullets : mSpaceShipBulletElement) {
        bullets -> draw();
    }

    SDLElement::draw();
}

void SpaceShip::update() {
    //Switch between frames to make animation for SpaceShip
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 3));

    if (tdInputHandler::Instance() -> readKey(SDL_SCANCODE_A) || tdInputHandler::Instance() -> readKey(SDL_SCANCODE_LEFT)) {
        mVelocity.setX(-3);
    }
    if (tdInputHandler::Instance() -> readKey(SDL_SCANCODE_D) || tdInputHandler::Instance() -> readKey(SDL_SCANCODE_RIGHT)) {
        mVelocity.setX(3);
    }
    if (tdInputHandler::Instance() -> readKey(SDL_SCANCODE_SPACE)) {
        mSpaceShipBullet = new SpaceShipBullet(new LoadParameters(mPos.getX() + 22, mPos.getY(), 15, 25, "spaceShipBullet"));

        //Push new bullet in vector (and play audio) if empty and pushing space-button
        //If new bullet goes out of screen, clear vector and pause audio (if necessary)
        if (mSpaceShipBulletElement.empty()) {
            mSpaceShipBulletElement.push_back(mSpaceShipBullet);
            tdAudioSpaceShip::Instance() -> playAudio();
        }
        if (mSpaceShipBulletElement[0]->getPos().getY() < 0) {
            mSpaceShipBulletElement.clear();
            tdAudioSpaceShip::Instance() -> pauseAudio();
        }

    }

    for (auto & bullets : mSpaceShipBulletElement) {
        bullets -> update();
    }

    //Limit spaceship to not fly out of screen
    if (mPos.getX() < 0) {
        mVelocity.setX(3);
    } else if (mPos.getX() > 595) {
        mVelocity.setX(-3);
    }

    SDLElement::update();
}

void SpaceShip::clean() {
    mSpaceShipBulletElement.clear();
}

SpaceShip::~SpaceShip() {
    delete mSpaceShipBullet;
}