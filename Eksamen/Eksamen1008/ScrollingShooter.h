#ifndef EKSAMEN1008_SCROLLINGSHOOTER_H
#define EKSAMEN1008_SCROLLINGSHOOTER_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <iostream>

#include "Handlers/TextureHandler.h"
#include "Element.h"
#include "GameElements/SpaceShip.h"
#include "GameElements/EnemyBlob.h"
#include "StateMachine/StateMachineScrollingShooter.h"
#include "StateMachine/MenuState.h"
#include "StateMachine/PlayState.h"

class ScrollingShooter {
public:
    bool init(const char* title, int x, int y, int width, int height, int flags);

    void update();
    void render();
    void handleStates();
    void clean();
    void quit() {
        mRunning = false;
    }

    [[nodiscard]] bool running() const {
        return mRunning;
    }

    //Checking for instance of ScrollingShooter
    static ScrollingShooter *Instance() {
        if (mInstance == nullptr) {
            mInstance = new ScrollingShooter();
            return mInstance;
        }

        return mInstance;
    }

    [[nodiscard]] SDL_Renderer *getRenderer() const {
        return mRenderer;
    }

    StateMachineScrollingShooter *getStateMachine() {
        return mStateMachineScrollingShooter;
    }

private:
    ScrollingShooter() = default;
    ~ScrollingShooter();

    static ScrollingShooter *mInstance;

    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;

    int mCurrentFrame;
    bool mRunning;

    StateMachineScrollingShooter *mStateMachineScrollingShooter;
};

typedef ScrollingShooter tdScrollingShooter;

#endif //EKSAMEN1008_SCROLLINGSHOOTER_H
