#ifndef EKSAMEN1008_PLAYSTATE_H
#define EKSAMEN1008_PLAYSTATE_H

#include <vector>

#include "GameState.h"
#include "../GameElements/SpaceShipBullet.h"
#include "../GameElements/SpaceShip.h"
#include "../GameElements/EnemyBlob.h"
#include "../GameElements/EnemyAlien.h"
#include "../GameElements/EnemyAngrySun.h"
#include "../GameElements/Health.h"
#include "../GameElements/LifeLost.h"
#include "../Handlers/TextureHandler.h"
#include "../ScrollingShooter.h"
#include "../Handlers/InputHandler.h"
#include "PauseState.h"
#include "../StateMachine/GameOverState.h"
#include "../Handlers/TextFontHandler.h"
#include "../AudioClasses/AudioSpaceShipExplosion.h"

class Element;
class SDLElement;

class PlayState : public GameState{
public:
    void update() override;
    void render() override;

    bool enter() override;
    bool exit() override;

    [[nodiscard]] std::string getStateId() const override{
        return mPlayID;
    }

private:
    ~PlayState();

    bool checkCollision(SDLElement *element1, SDLElement *element2);

    void enemyTakeDamage();
    void spaceShipTakeDamage();
    void updateHealth();
    void lifeLost();
    void loadElementTextures();
    void clearAllElementsFromTextureMap();

    static const std::string mPlayID;

    int mPointsCounter = 0;

    Health *mHealth;
    SpaceShip *mSpaceShip;
    EnemyBlob *mEnemyBlob;
    EnemyAlien *mEnemyAlien;
    EnemyAngrySun *mEnemyAngrySun;

    LifeLost *mLifeLost;
    std::vector<SDLElement*> mHealthElement;
    std::vector<SDLElement*> mSpaceShipElement;
    std::vector<SDLElement*> mEnemyBlobElement;
    std::vector<SDLElement*> mEnemyAlienElement;
    std::vector<SDLElement*> mEnemyAngrySunElement;

    std::vector<SDLElement*> mLifeLostElement;
};


#endif //EKSAMEN1008_PLAYSTATE_H
