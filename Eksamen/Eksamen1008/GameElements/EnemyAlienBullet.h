#ifndef EKSAMEN1008_ENEMYALIENBULLET_H
#define EKSAMEN1008_ENEMYALIENBULLET_H

#include <SDL_timer.h>

#include "../SDLElement.h"

class EnemyAlienBullet : public SDLElement {
public:
    explicit EnemyAlienBullet(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;
};

#endif //EKSAMEN1008_ENEMYALIENBULLET_H
