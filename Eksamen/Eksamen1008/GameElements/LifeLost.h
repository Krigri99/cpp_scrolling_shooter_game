#ifndef EKSAMEN1008_LIFELOST_H
#define EKSAMEN1008_LIFELOST_H

#include <SDL_timer.h>

#include "../SDLElement.h"

class LifeLost : public SDLElement {
public:
    explicit LifeLost(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;
};


#endif //EKSAMEN1008_LIFELOST_H
