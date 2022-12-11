#ifndef EKSAMEN1008_SDLELEMENT_H
#define EKSAMEN1008_SDLELEMENT_H

#include "Element.h"
#include "LoadParameters.h"
#include "Vector2D.h"

class SDLElement : public Element {
public:
    explicit SDLElement(const LoadParameters *params);

    void draw() override;
    void update() override;
    void clean() override {}

    Vector2D &getPos() {
        return mPos;
    }

    [[nodiscard]] int getWidth() const {
        return mWidth;
    }
    [[nodiscard]] int getHeight() const {
        return mHeight;
    }

    Vector2D mVelocity;
protected:
    Vector2D mPos;
    Vector2D mAcceleration;

    int mWidth;
    int mHeight;

    std::string mId;

    int mCurrentFrame;
};


#endif //EKSAMEN1008_SDLELEMENT_H
