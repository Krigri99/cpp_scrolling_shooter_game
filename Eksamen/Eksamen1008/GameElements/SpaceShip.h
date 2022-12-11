#ifndef EKSAMEN1008_SPACESHIP_H
#define EKSAMEN1008_SPACESHIP_H

#include <vector>
#include "../SDLElement.h"
#include "../AudioClasses/AudioSpaceShip.h"

class SpaceShip : public SDLElement{
public:
    explicit SpaceShip(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;
    void clean() override;

    std::vector<SDLElement*> getSpaceShipBullets() {
        return mSpaceShipBulletElement;
    }

    ~SpaceShip() override;
private:

    std::vector<SDLElement*> mSpaceShipBulletElement;

    SDLElement *mSpaceShipBullet;
};

#endif //EKSAMEN1008_SPACESHIP_H
