#ifndef EKSAMEN1008_GAMEOVERSTATE_H
#define EKSAMEN1008_GAMEOVERSTATE_H

#include <vector>

#include "GameState.h"
#include "../ScrollingShooter.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GraphicHeader.h"
#include "MenuChoice.h"
#include "../AudioClasses/AudioGameOver.h"

class Element;

class GameOverState : public GameState{
public:
    void update() override;
    void render() override;

    bool enter() override;
    bool exit() override;

    [[nodiscard]] std::string getStateId() const override {
        return mGameOverID;
    }

private:
    ~GameOverState();

    static void gameOverToMain();
    static void restart();

    static const std::string mGameOverID;

    std::vector<Element*> mElements;

    Element *mGameOverHeader;
    Element *mMainMenuBtn;
    Element *mRestartBtn;

};


#endif //EKSAMEN1008_GAMEOVERSTATE_H
