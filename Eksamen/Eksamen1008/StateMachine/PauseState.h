#ifndef EKSAMEN1008_PAUSESTATE_H
#define EKSAMEN1008_PAUSESTATE_H

#include <vector>

#include "GameState.h"
#include "../Handlers/TextureHandler.h"
#include "../Handlers/InputHandler.h"
#include "StateMachineScrollingShooter.h"
#include "MenuChoice.h"
#include "GraphicHeader.h"

class Element;

class PauseState :  public GameState{
public:
    void update() override;
    void render() override;

    bool enter() override;
    bool exit() override;

    [[nodiscard]] std::string getStateId() const override {
        return mPauseID;
    }

private:
    ~PauseState();

    static void pauseToMain();
    static void resume();

    static const std::string mPauseID;

    std::vector<Element*> mElements;

    Element *mGamePausedHeader;
    Element *mResumeBtn;
    Element *mMainMenuBtn;

};


#endif //EKSAMEN1008_PAUSESTATE_H
