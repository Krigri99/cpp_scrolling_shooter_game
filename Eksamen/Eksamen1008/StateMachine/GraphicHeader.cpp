#include "GraphicHeader.h"

void GraphicHeader::draw() {
    SDLElement::draw();
}

void GraphicHeader::update() {
    //Switch between frames to make animation for objects deriving from GraphicHeader
    mCurrentFrame = int (((SDL_GetTicks() / 100) % 2));
}
