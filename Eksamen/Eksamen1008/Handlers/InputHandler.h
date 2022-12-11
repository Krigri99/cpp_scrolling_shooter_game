#ifndef EKSAMEN1008_INPUTHANDLER_H
#define EKSAMEN1008_INPUTHANDLER_H

#include <vector>
#include <utility>
#include <SDL.h>

#include "../Vector2D.h"
#include "../ScrollingShooter.h"

class InputHandler {
public:
    bool readKey(SDL_Scancode key);

    void update();

    bool getMouseChoiceState(int choiceNumber) {
        return mMouseChoiceStates[choiceNumber];
    }

    Vector2D *getMousePos() {
        return mMousePos;
    }

    void reset();

    //Check for mInstance of InputHandler
    static InputHandler *Instance() {
        if (mInstance == nullptr) {
            mInstance = new InputHandler();
            return mInstance;
        }

        return mInstance;
    }

private:
    InputHandler();
    ~InputHandler();

    static InputHandler *mInstance;

    const Uint8 *mKeys;

    std::vector<bool> mMouseChoiceStates;
    Vector2D *mMousePos;

    //Keyboard interaction
    void keyDown();
    void keyUp();

    void mouseMove(SDL_Event &event);
    void mouseChoiceDown(SDL_Event &event);
    void mouseChoiceUp(SDL_Event &event);

};

typedef InputHandler tdInputHandler;

#endif //EKSAMEN1008_INPUTHANDLER_H
