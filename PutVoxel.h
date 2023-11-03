#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FigGeometrica.h"

class putVoxel : public FigGeometrica{
  int x, y, z;
  float r, g, b, a;
public:
    putVoxel(int x_, int y_, int z_, float r_, float g_, float b_, float a_);
    void draw(Sculptor &t);
};

#endif