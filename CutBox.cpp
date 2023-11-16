#include "CutBox.h"
#include <iostream>
#include "FigGeometrica.h"

/**Inicialização da classe CutBox através do metodo construtor.
*/
cutBox::cutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
  x0 = x0_;
  y0 = y0_;
  z0 = z0_;
  x1 = x1_;
  y1 = y1_;
  z1 = z1_;
}

/**Classe CutBox, com a função de apagar um bloco de voxels da matriz 3D, utilizando o metodo draw nas posições determinadas para identificar quais os elementos devem ser apagados pelo metodo cutVoxel presente na classe Sculptor.
*/

void cutBox::draw(Sculptor &t){
  for(int i=x0; i<=x1; i++){
    for(int j=y0; j<=y1; j++){
      for(int k=z0; k<=z1; k++){
        t.cutVoxel(i, j, k);
      }
    }
  }
}