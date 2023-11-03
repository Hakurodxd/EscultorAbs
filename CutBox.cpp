#include "CutBox.h"
#include <iostream>
#include "FigGeometrica.h"

cutBox::cutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
  x0 = x0_;
  y0 = y0_;
  z0 = z0_;
  x1 = x1_;
  y1 = y1_;
  z1 = z1_;
}

void cutBox::draw(Sculptor &t){
  for(int i=x0; i<=x1; i++){
    for(int j=y0; j<=y1; j++){
      for(int k=z0; k<=z1; k++){
        t.cutVoxel(i, j, k);
      }
    }
  }
}