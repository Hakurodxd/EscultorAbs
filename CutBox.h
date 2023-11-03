#ifndef CUTBOX_H
#define CUTBOX_H

#include "FigGeometrica.h"

class cutBox : public FigGeometrica{
  int x0, x1, y0, y1, z0, z1;
public:
    cutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_);
    void draw(Sculptor &t);
};

#endif