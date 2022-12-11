#include "TextureHandler.h"

TextureHandler *TextureHandler::mInstance = nullptr;

bool TextureHandler::loadTexture(const std::string& fileName, const std::string& id, SDL_Renderer *renderer) {
    //Initializing surface
    mSurface = IMG_Load(fileName.c_str());

    //Check if mSurface is initialized
    if (mSurface != nullptr) {
        //Converting mSurface to mTexture
        mTexture = SDL_CreateTextureFromSurface(renderer, mSurface);

        SDL_FreeSurface(mSurface);
        mSurface = nullptr;
    }

    //If all good, add mTexture to map
    if (mTexture != nullptr) {
        mTextureMap[id] = mTexture;
        return true;
    }

    return false;
}

void TextureHandler::drawFrame(const std::string& id, int x, int y, int w, int h, int currentFrame,
                               SDL_Renderer *renderer) {
    mSrcRect.x = w * currentFrame;
    mSrcRect.w = mDstRect.w = w;
    mSrcRect.h = mDstRect.h = h;
    mDstRect.x = x;
    mDstRect.y = y;

    SDL_RenderCopy(renderer, mTextureMap[id], &mSrcRect, &mDstRect);
}

void TextureHandler::clearFromTextureMap(const std::string& id) {
    mTextureMap.erase(id);
}

TextureHandler::~TextureHandler() {
    delete mInstance;
}
