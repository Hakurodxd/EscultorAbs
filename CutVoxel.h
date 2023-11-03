#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "FigGeometrica.h"

class cutVoxel : public FigGeometrica{
  int x, y, z;
public:
    cutVoxel(int x_, int y_, int z_);
    void draw(Sculptor &t);
};

#endif