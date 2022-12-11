#ifndef EKSAMEN1008_ENEMYANGRYSUN_H
#define EKSAMEN1008_ENEMYANGRYSUN_H

#include <vector>
#include <SDL_timer.h>

#include "../SDLElement.h"
#include "EnemyAngrySunBullet.h"
#include "../AudioClasses/AudioEnemyAngrySun.h"

class EnemyAngrySun : public SDLElement {
public:
    explicit EnemyAngrySun(const LoadParameters *params);

    void draw() override;
    void update() override;
    void clean() override;

    std::vector<SDLElement*> getAngrySunBullets() {
        return mAngrySunBulletElement;
    }

    ~EnemyAngrySun() override;
private:

    std::vector<SDLElement*> mAngrySunBulletElement;

    SDLElement *mAngrySunBullet;
};


#endif //EKSAMEN1008_ENEMYANGRYSUN_H
