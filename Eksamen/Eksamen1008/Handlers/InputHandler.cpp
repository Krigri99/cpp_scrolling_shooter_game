#include "InputHandler.h"

InputHandler *InputHandler::mInstance = nullptr;

InputHandler::InputHandler() : mKeys(nullptr), mMousePos(new Vector2D(0, 0)){
    for (int i = 0; i < 2; i++) {
        mMouseChoiceStates.push_back(false);
    }
}

void InputHandler::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                tdScrollingShooter::Instance() -> quit();
                break;
            case SDL_MOUSEMOTION:
                mouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseChoiceDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                mouseChoiceUp(event);
                break;
            case SDL_KEYDOWN:
                keyDown();
                break;
            case SDL_KEYUP:
                keyUp();
                break;
        }
    }
}

void InputHandler::mouseChoiceDown(SDL_Event &event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        mMouseChoiceStates[0] = true;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE) {
        mMouseChoiceStates[1] = true;
    }
}

void InputHandler::mouseChoiceUp(SDL_Event &event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        mMouseChoiceStates[0] = false;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE) {
        mMouseChoiceStates[1] = false;
    }
}

void InputHandler::mouseMove(SDL_Event &event) {
    mMousePos -> setX(event.motion.x);
    mMousePos -> setY(event.motion.y);
}

void InputHandler::keyDown() {
    mKeys = SDL_GetKeyboardState(nullptr);
}

void InputHandler::keyUp() {
    mKeys = SDL_GetKeyboardState(nullptr);
}

bool InputHandler::readKey(SDL_Scancode key) {
   if (mKeys != nullptr) {
        if (mKeys[key] == 1) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

void InputHandler::reset() {
    for (int i = 0; i < 2; i++) {
        mMouseChoiceStates.push_back(false);
    }
}

InputHandler::~InputHandler() {
    delete mInstance;
}

