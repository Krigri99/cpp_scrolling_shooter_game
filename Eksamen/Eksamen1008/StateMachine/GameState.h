#ifndef EKSAMEN1008_GAMESTATE_H
#define EKSAMEN1008_GAMESTATE_H

#include <string>
#include <vector>

class GameState {
public:
    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool enter() = 0;
    virtual bool exit() = 0;

    [[nodiscard]] virtual std::string getStateId() const = 0;

};

#endif //EKSAMEN1008_GAMESTATE_H
