#ifndef EKSAMEN1008_SPACESHIPBULLET_H
#define EKSAMEN1008_SPACESHIPBULLET_H

#include <SDL_timer.h>

#include "../SDLElement.h"

class SpaceShipBullet : public SDLElement {
public:
    explicit SpaceShipBullet(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;
};


#endif //EKSAMEN1008_SPACESHIPBULLET_H
