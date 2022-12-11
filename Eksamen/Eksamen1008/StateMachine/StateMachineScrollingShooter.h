#ifndef EKSAMEN1008_STATEMACHINESCROLLINGSHOOTER_H
#define EKSAMEN1008_STATEMACHINESCROLLINGSHOOTER_H

#include <vector>

#include "GameState.h"

class StateMachineScrollingShooter {
public:
    void addState(GameState *state);
    void changeState(GameState *state);
    void removeLastState();
    void update();
    void render();

private:
    std::vector<GameState*> mScrollingShooterStates;

};


#endif //EKSAMEN1008_STATEMACHINESCROLLINGSHOOTER_H
