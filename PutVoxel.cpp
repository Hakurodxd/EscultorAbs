#include "PutVoxel.h"
#include <iostream>
#include "FigGeometrica.h"

/**Inicialização da classe PutVoxel através do metodo construtor.
*/
putVoxel::putVoxel(int x_, int y_, int z_, float r_, float g_, float b_, float a_){
  x = x_;
  y = y_;
  z = z_;
  r = r_;
  g = g_;
  b = b_;
  a = a_;
}
/**Classe PutVoxel com a implementação do metodo Draw, a fim de desenhar um voxel em uma posição especifica.
*/
void putVoxel::draw(Sculptor &t){
  t.setColor(r, g, b, a);
  t.putVoxel(x, y, z);
}