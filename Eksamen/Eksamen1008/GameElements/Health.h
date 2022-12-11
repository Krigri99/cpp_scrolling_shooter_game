#ifndef EKSAMEN1008_HEALTH_H
#define EKSAMEN1008_HEALTH_H

#include "../SDLElement.h"

class Health : public SDLElement{
public:
    explicit Health(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;

    void setCurrentFrame(int frame) {
        mCurrentFrame += frame;
    }

    int getCurrentFrame() {
        return mCurrentFrame;
    }
};


#endif //EKSAMEN1008_HEALTH_H
