#ifndef EKSAMEN1008_ENEMYBLOB_H
#define EKSAMEN1008_ENEMYBLOB_H

#include <SDL_timer.h>

#include "../SDLElement.h"

class EnemyBlob : public SDLElement {
public:
    explicit EnemyBlob(const LoadParameters *params);

    void draw() override;
    void update() override;
};


#endif //EKSAMEN1008_ENEMYBLOB_H
