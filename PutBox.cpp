#include "PutBox.h"
#include <iostream>
#include "FigGeometrica.h"

putBox::putBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_, float r_, float g_, float b_, float a_){
  x0 = x0_;
  y0 = y0_;
  z0 = z0_;
  x1 = x1_;
  y1 = y1_;
  z1 = z1_;
  r = r_;
  g = g_;
  b = b_;
  a = a_;
}

void putBox::draw(Sculptor &t){
  t.setColor(r, g, b, a);
  for(int i=x0; i<=x1; i++){
    for(int j=y0; j<=y1; j++){
      for(int k=z0; k<=z1; k++){
        t.putVoxel(i, j, k);
      }
    }
  }
}