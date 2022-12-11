#include "StateMachineScrollingShooter.h"

void StateMachineScrollingShooter::addState(GameState *state) {
    mScrollingShooterStates.push_back(state);
    mScrollingShooterStates.back() -> enter();
}

void StateMachineScrollingShooter::changeState(GameState *state) {
    if (!mScrollingShooterStates.empty()) {
        if (mScrollingShooterStates.back() -> getStateId() == state -> getStateId()) {
            return;
        }

        if (mScrollingShooterStates.back() -> exit()) {
            mScrollingShooterStates.pop_back();
        }
    }

    mScrollingShooterStates.push_back(state);

    mScrollingShooterStates.back() -> enter();
}

void StateMachineScrollingShooter::removeLastState() {
    if (!mScrollingShooterStates.empty()) {
        if (mScrollingShooterStates.back() -> exit()) {
            mScrollingShooterStates.pop_back();
        }
    }
}

void StateMachineScrollingShooter::update() {
    if (!mScrollingShooterStates.empty()) {
        mScrollingShooterStates.back() -> update();
    }
}

void StateMachineScrollingShooter::render() {
    if (!mScrollingShooterStates.empty()) {
        mScrollingShooterStates.back() -> render();
    }
}
