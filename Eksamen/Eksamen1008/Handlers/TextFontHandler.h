#ifndef EKSAMEN1008_TEXTFONTHANDLER_H
#define EKSAMEN1008_TEXTFONTHANDLER_H

#include <string>
#include <SDL_render.h>
#include <SDL_ttf.h>

class TextFontHandler {
public:
    bool loadTextFont(const std::string &fileName, size_t size);

    void drawText(std::string text, int x, int y, int w, int h, SDL_Renderer* renderer);

    //Check for mInstance of TextFontHandler
    static TextFontHandler *Instance() {
        if (mInstance == nullptr) {
            mInstance = new TextFontHandler();
            return mInstance;
        }

        return mInstance;
    }

private:
    TextFontHandler() = default;
    ~TextFontHandler();

    static TextFontHandler *mInstance;

    SDL_Surface *mSurface{};
    SDL_Texture *mTexture{};

    TTF_Font *mFont{};

    SDL_Rect mRect{};
};

typedef TextFontHandler tdTextFontHandler;

#endif //EKSAMEN1008_TEXTFONTHANDLER_H
