#ifndef EKSAMEN1008_ELEMENT_H
#define EKSAMEN1008_ELEMENT_H

#include <string>

#include "LoadParameters.h"

class Element {
public:
    virtual ~Element() = default;

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    explicit Element(const LoadParameters *params) {}
};


#endif //EKSAMEN1008_ELEMENT_H
