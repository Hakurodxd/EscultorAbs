#include "CutVoxel.h"
#include <iostream>
#include "FigGeometrica.h"

/**Inicialização da classe CutVoxel através do metodo construtor.
*/
cutVoxel::cutVoxel(int x_, int y_, int z_){
  x = x_;
  y = y_;
  z = z_;
}

/**Classe CutVoxel, com a função de apagar apenas um voxel da matriz 3D, utilizando o metodo com mesmo nome, presente na classe Sculptor.
*/
void cutVoxel::draw(Sculptor &t){
  t.cutVoxel(x, y, z);
}