#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FigGeometrica.h"

class cutSphere : public FigGeometrica{
  int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int xcenter_, int ycenter_, int zcenter_, int radius_);
    void draw(Sculptor &t);
};

#endif