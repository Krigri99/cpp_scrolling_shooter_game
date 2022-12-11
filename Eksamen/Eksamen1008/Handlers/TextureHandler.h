#ifndef EKSAMEN1008_TEXTUREHANDLER_H
#define EKSAMEN1008_TEXTUREHANDLER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <map>

class TextureHandler {
public:
    bool loadTexture(const std::string &fileName, const std::string &id, SDL_Renderer *renderer);

    void drawFrame(const std::string &id, int x, int y, int w, int h, int currentFrame, SDL_Renderer *renderer);
    void clearFromTextureMap(const std::string &id);

    //Check for mInstance of TextureHandler
    static TextureHandler *Instance() {
        if (mInstance == nullptr) {
            mInstance = new TextureHandler();
            return mInstance;
        }

        return mInstance;
    }

private:
    TextureHandler() = default;
    ~TextureHandler();

    static TextureHandler *mInstance;

    std::map<std::string, SDL_Texture*> mTextureMap;

    SDL_Surface *mSurface{};
    SDL_Texture *mTexture{};

    SDL_Rect mSrcRect{};
    SDL_Rect mDstRect{};
};

typedef TextureHandler tdTextureHandler;

#endif //EKSAMEN1008_TEXTUREHANDLER_H
