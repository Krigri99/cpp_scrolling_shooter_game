#ifndef EKSAMEN1008_MENUCHOICE_H
#define EKSAMEN1008_MENUCHOICE_H

#include "../LoadParameters.h"
#include "../SDLElement.h"
#include "../Handlers/InputHandler.h"

class MenuChoice : public SDLElement{
public:
    MenuChoice(const LoadParameters* params, void (*callback)());

    void draw() override;
    void update() override;

private:
    void (*mCallback)();

};


#endif //EKSAMEN1008_MENUCHOICE_H
