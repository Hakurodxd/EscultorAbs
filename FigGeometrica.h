#ifndef FIGGEOMETRICA_H
#define FIGGEOMETRICA_H
#include "sculptor.h"

class FigGeometrica{
protected:
    float r,g,b,a;
public:
    FigGeometrica();
    virtual ~FigGeometrica(){}
    virtual void draw(Sculptor &t) = 0;
};

#endif