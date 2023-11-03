#ifndef PUTBOX_H
#define PUTBOX_H

#include "FigGeometrica.h"

class putBox : public FigGeometrica{
  int x0, x1, y0, y1, z0, z1;
  float r, g, b, a;
public:
    putBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_, float r_, float g_, float b_, float a_);
    void draw(Sculptor &t);
};

#endif