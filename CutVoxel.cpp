#include "CutVoxel.h"
#include <iostream>
#include "FigGeometrica.h"

cutVoxel::cutVoxel(int x_, int y_, int z_){
  x = x_;
  y = y_;
  z = z_;
}

void cutVoxel::draw(Sculptor &t){
  t.cutVoxel(x, y, z);
}