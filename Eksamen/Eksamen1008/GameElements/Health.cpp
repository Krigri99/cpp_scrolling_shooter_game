#include "Health.h"

void Health::draw() {
    SDLElement::draw();
}

void Health::update() {
    mCurrentFrame = getCurrentFrame();
}