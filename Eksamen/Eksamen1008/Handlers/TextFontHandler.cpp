#include "TextFontHandler.h"
#include <iostream>

TextFontHandler *TextFontHandler::mInstance = nullptr;

bool TextFontHandler::loadTextFont(const std::string &fileName, size_t size) {
    TTF_Init();

    //Initializing font
    mFont = TTF_OpenFont(fileName.c_str(), size);

    if (mFont == nullptr) {
        std::cout << "Error in loadTextFont: " << TTF_GetError() << std::endl;
    }

    return false;
}

void TextFontHandler::drawText(std::string text, int x, int y, int w, int h, SDL_Renderer *renderer) {
    mSurface = TTF_RenderText_Solid(mFont, text.c_str(), {255, 255, 255});

    if (mSurface != nullptr) {
        mTexture = SDL_CreateTextureFromSurface(renderer, mSurface);

        SDL_FreeSurface(mSurface);
        mSurface = nullptr;
    }

    mRect.x = x;
    mRect.y = y;
    mRect.w = w;
    mRect.h = h;

    SDL_RenderCopy(renderer, mTexture, nullptr, &mRect);
}

TextFontHandler::~TextFontHandler() {
    delete mInstance;
}