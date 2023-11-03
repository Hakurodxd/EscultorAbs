#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FigGeometrica.h"

class putSphere : public FigGeometrica{
  int xcenter, ycenter, zcenter, radius;
  float r, g, b, a;
public:
    putSphere(int xcenter_, int ycenter_, int zcenter_, int radius_, float r_, float g_, float b_, float a_);
    void draw(Sculptor &t);
};

#endif