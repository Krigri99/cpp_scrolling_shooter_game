#include "SDLElement.h"
#include "Handlers/TextureHandler.h"
#include "ScrollingShooter.h"

SDLElement::SDLElement(const LoadParameters *params) : Element(params), mPos(params -> getX(), params -> getY()),
                                                       mVelocity(0, 0), mAcceleration(0,0){
    mWidth = params -> getWidth();
    mHeight = params -> getHeight();
    mId = params -> getID();

    mCurrentFrame = 1;
}

void SDLElement::draw() {
    TextureHandler::Instance() -> drawFrame(mId, (int) mPos.getX(), (int) mPos.getY(),
                                            mWidth, mHeight, mCurrentFrame,
                                            tdScrollingShooter::Instance() -> getRenderer());
}

void SDLElement::update() {
    mVelocity += mAcceleration;
    mPos += mVelocity;
}
