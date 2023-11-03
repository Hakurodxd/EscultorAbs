#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FigGeometrica.h"

class putEllipsoid : public FigGeometrica{
  int xcenter, ycenter, zcenter, rx, ry, rz;
  float r, g, b, a;
public:
    putEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_, float r_, float g_, float b_, float a_);
    void draw(Sculptor &t);
};

#endif