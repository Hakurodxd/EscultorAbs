#include "CutSphere.h"
#include <iostream>
#include "FigGeometrica.h"

cutSphere::cutSphere(int xcenter_, int ycenter_, int zcenter_, int radius_){
  xcenter = xcenter_;
  ycenter = ycenter_;
  zcenter = zcenter_;
  radius = radius_;
}

void cutSphere::draw(Sculptor &t){
  for (int i = xcenter - radius; i <= xcenter + radius; i++) {
      for (int j = ycenter - radius; j <= ycenter + radius; j++) {
          for (int k = zcenter - radius; k <= zcenter + radius; k++) {
              int distancia = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter);
              if (distancia <= radius * radius) {
                t.cutVoxel(i, j, k);
              }
          }
      }
  }
}