#include "PutEllipsoid.h"
#include <iostream>
#include "FigGeometrica.h"

/**Inicialização da classe PutEllipsoid através do metodo construtor.
*/
putEllipsoid::putEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_, float r_, float g_, float b_, float a_){
  xcenter = xcenter_;
  ycenter = ycenter_;
  zcenter = zcenter_;
  rx = rx_;
  ry = ry_;
  rz = rz_;
  r = r_;
  g = g_;
  b = b_;
  a = a_;
}
/**Implementação do metodo Draw para desenhar uma elipse nas coordenadas determinadas, atraves do metodo putVoxel e a equação da elipse.
*/
void putEllipsoid::draw(Sculptor &t){
  t.setColor(r, g, b, a);
  for (int i = xcenter - rx; i <= xcenter + rx; i++) {
      for (int j = ycenter - ry; j <= ycenter + ry; j++) {
          for (int k = zcenter - rz; k <= zcenter + rz; k++) {
              float norma_x = float(i - xcenter) / rx;
              float norma_y = float(j - ycenter) / ry;
              float norma_z = float(k - zcenter) / rz;
              if ((norma_x * norma_x + norma_y * norma_y + norma_z * norma_z) <= 1.0) {
                t.putVoxel(i, j, k);
              }
          }
      }
  }
}