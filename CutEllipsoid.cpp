#include "CutEllipsoid.h"
#include <iostream>
#include "FigGeometrica.h"

cutEllipsoid::cutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_){
  xcenter = xcenter_;
  ycenter = ycenter_;
  zcenter = zcenter_;
  rx = rx_;
  ry = ry_;
  rz = rz_;

}

void cutEllipsoid::draw(Sculptor &t){
  for (int i = xcenter - rx; i <= xcenter + rx; i++) {
      for (int j = ycenter - ry; j <= ycenter + ry; j++) {
          for (int k = zcenter - rz; k <= zcenter + rz; k++) {
              float norma_x = float(i - xcenter) / rx;
              float norma_y = float(j - ycenter) / ry;
              float norma_z = float(k - zcenter) / rz;
              if ((norma_x * norma_x + norma_y * norma_y + norma_z * norma_z) <= 1.0) {
                t.cutVoxel(i, j, k);
              }
          }
      }
  }
}