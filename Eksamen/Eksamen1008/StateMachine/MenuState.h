#ifndef EKSAMEN1008_MENUSTATE_H
#define EKSAMEN1008_MENUSTATE_H

#include <vector>

#include "GameState.h"
#include "../Element.h"
#include "MenuChoice.h"
#include "../Handlers/TextureHandler.h"
#include "../ScrollingShooter.h"
#include "GraphicHeader.h"

class MenuState : public GameState{
public:
    void update() override;
    void render() override;

    bool enter() override;
    bool exit() override;

    [[nodiscard]] std::string getStateId() const override{
        return mMenuId;
    }

private:
    ~MenuState();

    static void menuToPlay();
    static void exitFromMenu();

    static const std::string mMenuId;

    std::vector<Element*> mElements;

    Element *mHeader;
    Element *mPlayBtn;
    Element *mQuitBtn;
};


#endif //EKSAMEN1008_MENUSTATE_H
