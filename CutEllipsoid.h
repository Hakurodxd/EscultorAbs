#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FigGeometrica.h"

class cutEllipsoid : public FigGeometrica{
  int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    cutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_);
    void draw(Sculptor &t);
};

#endif