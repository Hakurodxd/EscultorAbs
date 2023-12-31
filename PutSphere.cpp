#include "PutSphere.h"
#include <iostream>
#include "FigGeometrica.h"

/**Inicialização da classe PutSphere através do metodo construtor.
*/
putSphere::putSphere(int xcenter_, int ycenter_, int zcenter_, int radius_, float r_, float g_, float b_, float a_){
  xcenter = xcenter_;
  ycenter = ycenter_;
  zcenter = zcenter_;
  radius = radius_;
  r = r_;
  g = g_;
  b = b_;
  a = a_;
}
/**Implementação do metodo Draw para desenhar uma esfera nas coordenadas determinadas, com a equação da esfera para verificar se as coordenadas devem ser incluidas na figura pelo metodo putVoxel.
*/
void putSphere::draw(Sculptor &t){
  t.setColor(r, g, b, a);
  for (int i = xcenter - radius; i <= xcenter + radius; i++) {
      for (int j = ycenter - radius; j <= ycenter + radius; j++) {
          for (int k = zcenter - radius; k <= zcenter + radius; k++) {
              int distancia = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter);
              if (distancia <= radius * radius) {
                t.putVoxel(i, j, k);
              }
          }
      }
  }
}