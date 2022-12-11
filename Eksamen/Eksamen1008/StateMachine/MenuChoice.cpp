#include "MenuChoice.h"

MenuChoice::MenuChoice(const LoadParameters *params, void (*callback)()) : SDLElement(params), mCallback(callback) {
    mCurrentFrame = 0;
}

void MenuChoice::draw() {
    SDLElement::draw();
}

void MenuChoice::update() {
    Vector2D *mousePos = tdInputHandler::Instance() -> getMousePos();

    if (mousePos -> getX() < (mPos.getX() + mWidth) && mousePos -> getX() > (mPos.getX())
        && mousePos -> getY() < (mPos.getY() + mHeight) && mousePos -> getY() > mPos.getY()) {
        mCurrentFrame = 1;

        if (tdInputHandler::Instance() -> getMouseChoiceState(0)) {
            mCallback();
        }
    } else {
        mCurrentFrame = 0;
    }

}
