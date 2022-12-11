#ifndef EKSAMEN1008_ENEMYALIEN_H
#define EKSAMEN1008_ENEMYALIEN_H

#include <vector>
#include "../SDLElement.h"
#include "../AudioClasses/AudioEnemyAlien.h"

class EnemyAlien : public SDLElement {
public:
    explicit EnemyAlien(const LoadParameters *params);

    void draw() override;
    void update() override;
    void clean() override;

    std::vector<SDLElement*> getAlienBullets() {
        return mAlienBulletElement;
    }

    ~EnemyAlien() override;
private:

    std::vector<SDLElement*> mAlienBulletElement;

    SDLElement *mAlienBullet;
};


#endif //EKSAMEN1008_ENEMYALIEN_H
