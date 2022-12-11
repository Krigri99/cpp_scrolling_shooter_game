#ifndef EKSAMEN1008_GRAPHICHEADER_H
#define EKSAMEN1008_GRAPHICHEADER_H

#include <SDL_timer.h>

#include "../SDLElement.h"
#include "../LoadParameters.h"

class GraphicHeader : public SDLElement {
public:
    explicit GraphicHeader(const LoadParameters *params) : SDLElement(params) {}

    void draw() override;
    void update() override;

};


#endif //EKSAMEN1008_GRAPHICHEADER_H
