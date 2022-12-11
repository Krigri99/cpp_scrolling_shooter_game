#ifndef EKSAMEN1008_ENEMYANGRYSUNBULLET_H
#define EKSAMEN1008_ENEMYANGRYSUNBULLET_H

#include <SDL_timer.h>

#include "../SDLElement.h"

class EnemyAngrySunBullet : public SDLElement{
public:
    explicit EnemyAngrySunBullet(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;
};

#endif //EKSAMEN1008_ENEMYANGRYSUNBULLET_H
